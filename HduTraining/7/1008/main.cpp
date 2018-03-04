#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
char G[maxn][maxn];
int n, cnt_r, cnt_c, r[maxn][maxn], c[maxn][maxn], mp[maxn][maxn], vis[maxn], match[maxn];

bool dfs(int x)
{
  for (int j = 0; j < cnt_c; ++j) {
    if (mp[x][j] == 1 && vis[j] == 0) {
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
  //行
  for (int i = 0; i < cnt_r; ++i) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) ans ++;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  char x;
  while (cin >> n && n) {
    cnt_r = cnt_c = 0;
    memset(r, -1, sizeof(r));
    memset(c, -1, sizeof(c));
    memset(mp, 0, sizeof(mp));
    memset(match, -1, sizeof(match));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> G[i][j];
      }
    }
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (G[i][j] == '.' && r[i][j] == -1) {
          for (int k = j; k < n && G[i][k] == '.'; ++k)
            r[i][k] = cnt_r;
          cnt_r ++; 
        } 
        
        if (G[j][i] == '.' && c[j][i] == -1) {
          for (int k = j; k < n && G[k][i] == '.'; ++k)
            c[k][i] = cnt_c;
          cnt_c ++;
        }
      }
    }
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (G[i][j] == '.') 
          mp[r[i][j]][c[i][j]] = 1;
      }
    }    
    Hungary();
  }
  
  return 0;
}
