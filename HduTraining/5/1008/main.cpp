#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;
int t, n, k, max_an, max_deep;
int G[maxn][maxn], some[maxn][maxn], all[maxn][maxn];
  
void dfs(int deep, int sn, int an)
{
  if (sn == 0) {
    max_an = max(max_an, an);
    if (max_an == an) max_deep = deep;
  }
  
  int u = some[deep][0];
  
  for (int i = 0; i < sn; ++i) {
    int v = some[deep][i];
    //cout << v << "->" << u << ":" << G[u][v] << endl;
    if (G[u][v] == 1) continue;
    
    int tsn = 0;
    
    for (int j = 0; j < an; ++j) all[deep+1][j] = all[deep][j];
    all[deep+1][an] = v;
    
    for (int j = 0; j < sn; ++j) if(G[v][some[deep][j]]) some[deep+1][tsn++] = some[deep][j];
    dfs(deep+1, tsn, an+1);
    some[deep][i] = 0;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  cin >> t;
  while (t--) {
    cin >> n >> k;
    
    memset(G, 0, sizeof(G));
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (i!=j) G[i][j] = 1;
    
    for (int i = 0; i < k; ++i) {
      int a, b;
      cin >> a >> b;
      G[a][b] = G[b][a] = 0; //取补图
    }
    
    for (int i = 0; i < n; ++i) some[0][i] = i+1;
    
    max_an = -1;
    dfs(0, n, 0);
    
    cout << max_an << endl;
    cout << all[max_deep][0];
    for (int i = 1; i < max_an; ++i) cout << " " << all[max_deep][i];
    cout << endl;
  }
  

  return 0;
}
