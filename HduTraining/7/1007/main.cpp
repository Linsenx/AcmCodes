#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10;
int n, G[N][N], match[N], vis[N];

bool dfs(int x)
{
  for (int j = 0; j < n; ++j) {
    if (G[x][j] == 1 && vis[j] == 0) {
      vis[j] = 1;
      if (match[j] == -1 || dfs(match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

void Hungary()
{
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans ++;
  }
//  for (int i=0; i<n; ++i) cout << i <<" -> " << match[i] << endl;
  printf("%d\n", n - ans/2);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int a, b, cnt;
  while (~scanf("%d", &n)) {
    memset(G, 0, sizeof G);
    memset(match, -1, sizeof match);
    
    for (int i = 0; i < n; ++i) {
      scanf("%d: (%d)", &a, &cnt);
      while (cnt--) {
        scanf("%d", &b);
        G[a][b] = 1;
        //cout << "a:" << a << " b:" << b << endl;
      }
    }
    Hungary();
  }

  return 0;
}
