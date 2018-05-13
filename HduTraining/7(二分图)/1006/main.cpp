#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 510;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int n, m, G[maxn][maxn], mp[maxn][maxn], vis[maxn], match[maxn];
int N, _index, _a[maxn][maxn], _b[maxn]; //_a存index _b存index对应编号

bool dfs(int x)
{
  for (int j = 0; j < N; ++j) {
    if (mp[x][j] == 1 && !vis[j]) {
      vis[j] = 1;
      if (match[j] == -1 || dfs(match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

void output(int a, int b)
{
  int ax, ay, bx, by;
  ax = a / m + 1;
  ay = a % m + 1;
  
  bx = b / m + 1;
  by = b % m + 1;
  
  cout <<"("<<ax<<","<<ay<<")--("<<bx<<","<<by<<")"<<endl;
}

void Hungary()
{
  int ans = 0;
  memset(match, -1, sizeof(match));
  for (int i = 0; i < N; ++i) {
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) ans ++;
  }
  
  cout << ans << endl;
  for (int i = 0; i < N; ++i) {
    int a, b;
    a = i;
    b = match[a];
    if (b != -1 && a != b) {
      output(_b[a], _b[b]);
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
  
  int k, a, b, bid, nbid, nx, ny;
  while (cin >> n >> m) {
    if (!n && !m) break;
    cin >> k;
    N = _index = 0;
    memset(G, 0, sizeof(G));
    memset(mp, 0, sizeof(mp));
    memset(_a, 0, sizeof(_a));
    memset(_b, 0, sizeof(_b));
    while (k--) {
      cin >> a >> b;
      G[a-1][b-1] = 1;
    }
    
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (G[i][j] == 0) {
        _b[_index] = i * m + j;
        _a[i][j] = _index++;
      }
    }
    N = _index;
    
    //建图
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (G[i][j] == 0 && (i+j)%2 == 1) {
        for (int d = 0; d < 4; ++d) {
          nx = i + dir[d][0];
          ny = j + dir[d][1];
          if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
          if (G[nx][ny] == 1) continue;
          mp[_a[i][j]][_a[nx][ny]] = 1;        
          //cout << i << "," << j << "->" << nx << "," << ny << "|" <<endl;
        }
      }
    }
    Hungary();
    cout << endl;
  }

  return 0;
}
