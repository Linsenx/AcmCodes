#include <bits/stdc++.h>
using namespace std;


const int maxn = 1000;
const int inf = 1e9;
int n, m, kase;
int pre[maxn], flow[maxn], cap[maxn][maxn];

int bfs(int s, int e)
{
  memset(pre, -1, sizeof(pre));
  pre[s] = 0;
  flow[s] = inf;
  queue<int> Q;
  Q.push(s);

  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    if (u == e) break;
    for (int i = 1; i <= n; ++i) {
      if (i != s && pre[i] == -1 && cap[u][i] > 0) {
        pre[i] = u;
        flow[i] = min(flow[u], cap[u][i]);
        Q.push(i);
      }
    }
  }
  if (pre[e] == -1) return -1;
  else return flow[e];
}

void EK(int s, int e)
{
  int delta = 0;
  int maxflow = 0;
  while ((delta = bfs(s, e)) != -1) {
    int u = e;
    while (u != s) {
      int last = pre[u];
      cap[last][u] -= delta;
      cap[u][last] += delta;
      u = last;
    }
    maxflow += delta;
  }
  cout << "Case " << ++kase << ": " << maxflow << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int a, b, c;
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      cap[a][b] += c;
    }
    EK(1, n);
  }


  return 0;
}
