#include <bits/stdc++.h>
using namespace std;

const int N = 120 + 10;
int n, k, G[N][N], vis[N], match[N];

bool dfs(int x)
{
  for (int i = 1; i <= n; ++i)
  {
    if (G[x][i] == 1 && vis[i] == 0) {
      vis[i] = 1;
      if (match[i] == 0 || dfs(match[i])) {
        match[i] = x;
        return true;
      }
    }
  }
  return false;
}

int Hungary()
{
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans ++;
  }
  for (int i=1; i<=n; ++i) cout << i <<" -> " << match[i] << endl;
  cout << endl;

  return n - ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int test, a, b;
  cin >> test;
  while (test--) {
    cin >> n >> k;
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
