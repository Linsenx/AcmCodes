#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 500;
int n, m;
int pre[maxn], flow[maxn];
int capacity[maxn][maxn]; //≤–”‡Õ¯¬Á

int bfs(int s, int e)
{
  memset(pre, -1, sizeof(pre));
  pre[s] = 0;
  flow[s] = inf;
  queue<int> Q;
  Q.push(s);

  while(!Q.empty()) {
    int u = Q.front(); Q.pop();
    if (u == e)
      break;
    for (int i = 1; i <= m; ++i) {
      if (i != s && capacity[u][i] > 0 && pre[i] == -1) {
        pre[i] = u;
        flow[i] = min(capacity[u][i], flow[u]);
        Q.push(i);
      }
    }
  }
  if (pre[e] == -1)
    return -1;
  else
    return flow[e];
}

void EK(int s, int e)
{
  int delta = 0;
  int maxflow = 0;
  while ((delta=bfs(s,e)) != -1) {
    int u = e;
    while (u != s) {
      int before = pre[u];
      capacity[before][u] -= delta;
      capacity[u][before] += delta;
      u = before;
    }
    maxflow += delta;
  }
  cout << maxflow << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> n >> m) {
    int s, e, c;
    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));
    for (int i = 0; i < n; ++i) {
      cin >> s >> e >> c;
      capacity[s][e] += c;
    }
    EK(1, m);
  }

  return 0;
}
