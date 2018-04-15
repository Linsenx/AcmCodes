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

int mp[50][50];
int main()
{
  #ifdef LOCAL_DEBUG
    freopen("in.txt", "r", stdin);
  #endif

  Dinic dc;
  int n, x, sum, s, t;
  while (cin >> n) {
    sum = 0;
    s = 0;
    t = 1+n*n;
    dc.init(2+n*n);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> x;
      sum += x;
      if ((i+j) % 2 == 0) {
        dc.AddEdge(s, 1+i*n+j, x);
        //up
        if (i-1 >= 0) dc.AddEdge(1+i*n+j, 1+(i-1)*n+j, INF);
        //down
        if (i+1 <= n-1) dc.AddEdge(1+i*n+j, 1+(i+1)*n+j, INF);
        //left
        if (j-1 >= 0) dc.AddEdge(1+i*n+j, 1+i*n+(j-1), INF);
        //right
        if (j+1 <= n-1) dc.AddEdge(1+i*n+j, 1+i*n+(j+1), INF);
      } else {
        dc.AddEdge(1+i*n+j, t, x);
      }
    }
    int res = sum - dc.Maxflow(s, t);
    cout << res << endl;
  }


  return 0;
}
