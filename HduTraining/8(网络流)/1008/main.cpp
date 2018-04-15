#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int maxn = 20000+10;
int mp[150][150][2];
int n, m, sp, ep, cnt_hang, cnt_lie, cnt_white, hang[maxn], lie[maxn], gz[maxn], pos[maxn];

struct Edge
{
  int from, to, cap, flow;
  Edge() {}
  Edge(int a, int b, int c, int d): from(a),to(b),cap(c),flow(d) {}
};

struct Dinic
{
  int n, m, s, t;      //边数，源点，汇点
  vector<Edge> edges;  //边表
  vector<int> G[maxn]; //邻接表
  bool vis[maxn];
  int d[maxn];         //源点到i的距离
  int cur[maxn];       //当前弧下标

  void init(int n)
  {
    for (int i = 0; i < n; ++i) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  int BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }

  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }

  int Maxflow(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }

}dc;

Dinic DC;

int find_white_blocks(int x, int y, int dirx, int diry)
{
  int cnt = 0;
  if (dirx != 0) {
    //固定y轴
    int nx = x;
    while (mp[nx][y][0] == -2 || mp[nx][y][1] == -2) {
      nx += dirx;
      cnt ++;
    }
  } else {
    //固定x轴
    int ny = y;
    while (mp[x][ny][0] == -2 || mp[x][ny][1] == -2) {
      ny += diry;
      cnt ++;
    }
  }
  return cnt;
}

int find_near_hang(int x, int y)
{
  int nx = x, ny = y;
  while (mp[nx][ny][1] < 0) {
    ny --;
  }
  return hang[nx*m+ny];
}

int find_near_lie(int x, int y)
{
  int nx = x, ny = y;
  while (mp[nx][ny][0] < 0) {
    nx--;
  }
  return lie[nx*m+ny];
}

int main()
{
  #ifdef LOCAL_DEBUG
    freopen("in.txt", "r", stdin);
  #endif

  int left, right;
  string block, lft, rht;
  while (cin >> n >> m) {
    sp = 0;
    cnt_hang = cnt_lie = cnt_white = 0;
    DC.init(maxn);
    memset(mp, 0, sizeof(mp));
    memset(hang, 0, sizeof(hang));
    memset(lie, 0, sizeof(lie));
    memset(gz, 0, sizeof(gz));
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < m; ++j) {
        cin >> block;
        lft.clear(); rht.clear();
        int flag = 0;
        for (auto ch : block) {
          if (ch == '\\') {
            flag = 1;
            continue;
          }
          if (flag == 0) lft += ch;
          else if (flag == 1) rht += ch;
        }
        if (lft[0] == 'X') left = -1;
        else if (lft[0] == '.') left = -2;
        else if (lft.size() > 0) left = stoi(lft);
        else left = -1;
        if (rht[0] == 'X') right = -1;
        else if (rht[0] == '.') right = -2;
        else if (rht.size() > 0) right = stoi(rht);
        else right = -1;
        mp[i][j][0] = left;
        mp[i][j][1] = right;
        if (left == -2) gz[i*m+j] = ++cnt_white;
        if (right > 0) hang[i*m+j] = ++cnt_hang;
        if (left > 0) lie[i*m+j] = ++cnt_lie;
      }
    }

    ep = cnt_hang+cnt_white+cnt_lie+1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      //如果当前格子右上角有数字，连接S->(i,j)
      if (mp[i][j][1] > 0) {
        DC.AddEdge(sp, hang[i*m+j], mp[i][j][1]-find_white_blocks(i,j+1,0,1));
        //cout << "S->(i,j): " << sp << "->" << hang[i*m+j] << "|" << mp[i][j][1]-find_white_blocks(i,j,0,1) << endl;
      }
      //如果当前格子左下角有数字，连接(i,j)->T
      if (mp[i][j][0] > 0) {
        DC.AddEdge(cnt_hang+cnt_white+lie[i*m+j], ep, mp[i][j][0]-find_white_blocks(i+1,j,1,0));
        //cout << "(i,j)->T: " << cnt_hang+cnt_white+lie[i*m+j] << "->" << ep << endl;
      }

      //如果当前格子是空格，连接离格子最近的行列
      if (mp[i][j][0] == -2) {
        int near_hang = find_near_hang(i, j);
        int near_lie = find_near_lie(i, j);
        pos[i*m+j] = DC.edges.size();
        //cout << "hang->(i,j)->lie: " << near_hang << "->" << cnt_hang+gz[i*m+j] << "->" << cnt_hang+cnt_white+near_lie <<endl;
        DC.AddEdge(near_hang, cnt_hang+gz[i*m+j], 8);
        DC.AddEdge(cnt_hang+gz[i*m+j], cnt_hang+cnt_white+near_lie, 8);
      }
    }
    DC.Maxflow(sp, ep);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mp[i][j][0]!=-2) cout << "_";
        else cout << (1+DC.edges[pos[i*m+j]].flow);
        if (j != m-1) cout << " ";
      }
      cout << endl;
    }

    /*cout << DC.edges[pos[1*m+1]].flow << endl;
    cout << DC.edges[pos[1*m+2]].flow << endl;
    cout << DC.edges[pos[1*m+3]].flow << endl;
    cout << DC.edges[pos[1*m+4]].flow << endl;*/
  }


  return 0;
}
