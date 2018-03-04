#include <bits/stdc++.h>
using namespace std;

const int N = 200 + 10;
int n, m, k, G[N][N], vis[N], match[N], ans;

bool dfs(int x)
{
  for (int j = 1; j < m; ++j)
  {
    if (G[x][j] == 1 && vis[j] == 0)
    {
      vis[j] = 1;
      if (match[j] == -1 || dfs(match[j])) 
      {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n, n)
  {
    cin >> m >> k;
    memset(G, 0, sizeof(G));
    memset(match, -1, sizeof match);
    int c, x, y;
    while (k--)
    {
      cin >> c >> x >> y;
      if (x && y) G[x][y] = 1;
    }
    
    ans = 0;
    for (int i = 1; i < n; ++i)
    {
      memset(vis, 0, sizeof vis);
      if (dfs(i)) ans ++;
    }
    cout << ans << endl;
  }

  return 0;
}
