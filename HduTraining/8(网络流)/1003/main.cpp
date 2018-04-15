#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int maxn = 2200;
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
int main()
{
  #ifdef LOCAL_DEBUG
    freopen("in.txt", "r", stdin);
  #endif

  int test, n, m, p, s, e, sum;
  int tl, tr;
  scanf("%d", &test);
  while (test--) {
    sum = 0;
    tl = INF, tr = -INF;
    scanf("%d%d", &n, &m);
    dc.init(maxn+n+5);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d", &p, &s, &e);
      sum += p;
      dc.AddEdge(1, 1+i, p);
      for (int j = s; j <= e; ++j) {
        dc.AddEdge(1+i, 1+n+j, 1);
      }
      tl = min(tl, s);
      tr = max(tr, e);
    }
    int t = 1+n+tr+1;
    for (int i = 1+n+tl; i <= 1+n+tr; ++i) {
      dc.AddEdge(i, t, m);
    }
    if (dc.Maxflow(1, t) == sum) printf("Case %d: Yes\n\n",++kase);
    else printf("Case %d: No\n\n",++kase);
  }



  return 0;
}
