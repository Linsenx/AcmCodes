#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10;
int k, m, n, G[N][N], vis[N], match[N];

bool dfs(int x)
{
  for (int j = 1; j <= n; ++j) {
    if (G[x][j] == 1 && vis[j] == 0) {
      vis[j] = 1;
      if (match[j] == 0 || dfs(match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int Hungary()
{
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans ++;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int a, b;
  while (cin >> k && k)
  {
    cin >> m >> n;
    memset(G, 0, sizeof G);
    memset(match, 0, sizeof match);
    while (k--) {
      cin >> a >> b;
      G[a][b] = 1;
    }
    cout << Hungary() << endl;
  }

  return 0;
}
