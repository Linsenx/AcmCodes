#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7 + 10;
int dis[101][101];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, m;
  int a, b, c;
  while (cin >> n >> m && n + m) {
    //init dis array
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = i == j ? 0 : inf;
    
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      dis[a-1][b-1] = c;
      dis[b-1][a-1] = c;
    }
    
    //floyd
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
          
    cout << dis[0][n-1] << endl;
  }

  return 0;
}
