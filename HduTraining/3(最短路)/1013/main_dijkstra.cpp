#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1010;
const int INF = 1e9;

int V;
int d[MAX_V], m[MAX_V];
int cost[MAX_V][MAX_V], mcost[MAX_V][MAX_V];
bool used[MAX_V];


void dijkstra(int s)
{
  fill(m, m + V, 0);
  fill(d, d + V, INF);
  fill(used, used + V, false);
  for (int i = 0; i < V; ++i) {
    d[i] = cost[s][i];
    m[i] = mcost[s][i];
  }
  d[s] = 0;
  m[s] = 0;
  used[s] = true;
    
  while (true) {
    int v = -1;
    int minDistant = INF;
    int minMoney = INF;
    for (int u = 0; u < V; ++u) {
      if (!used[u] && (d[u] < minDistant || (d[u] == minDistant && m[u] < minMoney))) {
        minDistant = d[u];
        minMoney = m[u];
        v = u;
      }
    }
    if (v == -1) break;
    used[v] = true;
    
    for (int u = 0; u < V; ++u) {
      if (!used[u] && (d[u] > d[v] + cost[v][u] || (d[u] == d[v] + cost[v][u] && m[u] > m[v] + mcost[v][u]))) {
        d[u] = d[v] + cost[v][u];
        m[u] = m[v] + mcost[v][u];
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int s, t;
  int n0, m0, a0, b0, d0, p0;
  while (cin >> n0 >> m0 && n0 + m0) {
    V = n0;
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j)
        cost[i][j] = mcost[i][j] = INF;
        
    for (int i = 0; i < m0; ++i) {
      cin >> a0 >> b0 >> d0 >> p0;
      if ((cost[a0-1][b0-1] == INF && mcost[a0-1][b0-1] == INF) || (d0 < cost[a0-1][b0-1] || (d0 == cost[a0-1][b0-1] && p0 < mcost[a0-1][b0-1]))) {
        cost[a0-1][b0-1] = cost[b0-1][a0-1] = d0;
        mcost[a0-1][b0-1] = mcost[b0-1][a0-1] = p0;
      }
      
    }
    cin >> s >> t;
    s--;t--;
    dijkstra(s);
    cout << d[t] << " " << m[t] << endl;
  }

  return 0;
}
