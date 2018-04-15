#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int maxn = 5000;
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

Dinic dinic;

int tt[maxn], si[maxn], ei[maxn], ni[maxn], ti[maxn], tot;
int main()
{
  #ifdef LOCAL_DEBUG
    freopen("in.txt", "r", stdin);
  #endif

  int n, m;
  int t_l, t_r, sum;
  while (cin >> n >> m) {
    tot = sum = 0;
    t_l = INF, t_r = -INF;
    memset(tt, 0, sizeof tt);
    for (int i = 1; i <= n; ++i) {
      cin >> si[i] >> ni[i] >> ei[i] >> ti[i];
      sum += ti[i]*ni[i];
      tt[tot++] = si[i];
      tt[tot++] = ei[i];
    }
    sort(tt, tt+tot);
    tot = unique(tt, tt+tot) - tt;
    int sp = 0, ep = 2+n+tot;
    dinic.init(2+n+tot);
    for (int i = 1; i <= n; ++i) dinic.AddEdge(sp, i, ni[i]*ti[i]);
    for (int i = 1; i <= tot-1; ++i) {
      dinic.AddEdge(n+i, ep, (tt[i]-tt[i-1])*m);
      //cout << n+i << "=>" << (tt[i]-tt[i-1])*m << endl;
      for (int j = 1; j <= n; ++j) {
        if (si[j] <= tt[i-1] && tt[i] <= ei[j]) {
          dinic.AddEdge(j, n+i, INF);
        }
      }
    }

    if (sum == dinic.Maxflow(sp, ep)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
