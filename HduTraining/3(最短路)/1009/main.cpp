#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
const int INF = 1e9;
int V, endp;
vector<int> starp;
int d[N];
bool used[N];
int cost[N][N];

void dijkstra(int s)
{
  fill(d + 1, d + V + 1, INF);
  fill(used + 1, used + V + 1, false);
  d[s] = 0;

  while (true) {
    int v = -1;
    for (int u = 1; u <= V; ++u) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if (v == -1) break;
    used[v] = true;
    
    for (int u = 1; u <= V; ++u) {
      if (!used[u] && d[u] > d[v] + cost[v][u]) {
        d[u] = d[v] + cost[v][u];
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
  
  int n, m, s, p, q, t, w, x;
  while (cin >> n >> m >> s) {
    V = n;
    endp = s;
    starp.clear();
    for (int i = 1; i <= V; ++i)
      for (int j = 1; j <= V; ++j)
        cost[i][j] = INF;
      
    while (m--) {
      cin >> p >> q >> t;
      //终点当作起点
      if (cost[q][p] > t)
        cost[q][p] = t;
    }
    
    cin >> w;
    while (w--) {
      cin >> x;
      starp.push_back(x);
    }
    
    dijkstra(endp);
    
    int min_len = INF;
    for (auto sp : starp) {
      //cout << sp << endl;
      min_len = min(min_len, d[sp]);
    }
    cout << (min_len == INF ? -1 : min_len) << endl;
  }

  return 0;
}
