#include <bits/stdc++.h>
using namespace std;

const int INF = 0xfffffff;
const int maxn = 100 + 10;
int d[maxn][maxn];
int path[maxn][maxn];
int point[maxn];
int V, kase;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n;
    V = n + 1;
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j) {
        d[i][j] = -INF;
      }
    
    for (int i = 0; i < n; ++i) {
      cin >> point[i];
    }
      
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      a--;b--;
      if (b != n) d[a][b] = point[b];
      else d[a][b] = 0;
      path[a][b] = b;
    }
    
    int maxp = 0;
    for (int k = 0; k < V; ++k)
      for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j) {
          if (d[i][k] != -INF && d[k][j] != -INF && d[i][j] < d[i][k] + d[k][j]) {
            d[i][j] = d[i][k] + d[k][j];
            path[i][j] = path[i][k];
          }
        }
    
    cout << "CASE " << ++kase << "#" << endl;
    cout << "points : " << d[0][V-1] << endl;
    cout << "circuit : 1" ;
    
    int u = 0;
    while (u != V - 1) {
      cout << "->"  << (path[u][V-1] == n ? 1 : path[u][V-1] + 1);
      u = path[u][V-1];
    }
    cout << endl;
    if(t != 0) cout << endl;
  }
  return 0;
}
