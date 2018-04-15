#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int maxn = 1000+10;
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

int kase;
int value[maxn][maxn], lizards[maxn][maxn];
int main()
{
  #ifdef LOCAL_DEBUG
    freopen("in.txt", "r", stdin);
  #endif

  Dinic dc;
  int test, row, col, jump, sum;
  cin >> test;
  while (test--) {
    cin >> row >> jump;
    sum = 0;
    memset(value, 0, sizeof value);
    memset(lizards, 0, sizeof lizards);
    for (int i = 1; i <= row; ++i) {
      string line;
      cin >> line;
      col = line.length();
      for (int j = 1; j <= line.length(); ++j) {
        value[i][j] = line[j-1] - '0';
      }
    }
    for (int i = 1; i <= row; ++i) {
      string line;
      cin >> line;
      for (int j = 1; j <= line.length(); ++j) {
        if (line[j-1] == 'L') lizards[i][j] = 1, ++sum;
        else lizards[i][j] = 0;
      }
    }
    int sp = 0;
    int ep = row*col*2+1;
    dc.init(row*col*2+2);
    for (int i = 1; i <= row; ++i) {
      for (int j = 1; j <= col; ++j) {
        if (value[i][j] > 0) {
          if (i <= jump || j <= jump || i+jump > row || j+jump > col) {
            //dc.AddEdge((i-1)*col+j, (i-1)*col+j+n*m, value[i][j]);
            //dc.AddEdge((i-1)*col+j+n*m, ep, value[i][j]);
            dc.AddEdge((i-1)*col+j+row*col, ep, value[i][j]);
          } else {
            //cout << i << "," << j << ":" << value[i][j] <<endl;
            for (int ii = 1; ii <= row; ++ii) {
              for (int jj = 1; jj <= col; ++jj) {
                if (abs(i-ii)+abs(j-jj)<=jump && value[ii][jj] > 0 && !(i == ii && j == jj)) {
                  //cout <<"----" <<i << "," << j << " -> " << ii << "," << jj << "[" << abs(i-ii)+abs(j-jj) << "]" << endl;
                  dc.AddEdge((i-1)*col+j+col*row, (ii-1)*col+jj, INF);
                }
              }
            }
          }

          dc.AddEdge((i-1)*col+j, (i-1)*col+j+row*col, value[i][j]);
          if (lizards[i][j] == 1) {
            dc.AddEdge(sp, (i-1)*col+j, 1);
            //cout << "--" << i << "," << j << endl;
          }
        }
      }
    }
    //cout << dc.Maxflow(sp, ep) << endl;
    int left_liz = sum - dc.Maxflow(sp, ep);
    cout << "Case #" << ++kase << ": ";
    if (left_liz == 0) cout << "no lizard was left behind.\n";
    else if (left_liz == 1) cout << "1 lizard was left behind.\n";
    else cout << left_liz << " lizards were left behind.\n";
  }



  return 0;
}
