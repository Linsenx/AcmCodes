#include <bits/stdc++.h>
using namespace std;

int n, m;
int ex, ey;
int flag = 0;
int vis[1010][1010];
int mp[1010][1010];
int di[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int x, int y, int cnt, int dir)
{  
  if (flag == 1) {
    return;
  }
  if (cnt == 2 && x != ex && y != ey) {
    return;
  }
  if (cnt > 2) {
    return;
  }
  if (x == ex && y == ey) {
    flag = 1;
    return;
  }
  
  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + di[i][0];
    ny = y + di[i][1];
    if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
    if ((mp[nx][ny] == 0 || mp[nx][ny] == mp[ex][ey]) && vis[nx][ny] == 0) {
      vis[nx][ny] = 1;
      dfs(nx, ny, i == dir ? cnt : cnt + 1, i);
      vis[nx][ny] = 0;
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


  while (cin >> n >> m && n * m) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        cin >> mp[i][j];
      }
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      flag = 0;
      ex = x2;
      ey = y2;
      
      if (mp[x1][y1] != mp[x2][y2]) {
        cout << "NO" << endl;
      } else if (mp[x1][y1] == 0 || mp[x2][y2] == 0) {
        cout << "NO" << endl;
      } else if (x1 == x2 && y1 == y2) {
        cout << "NO" << endl;
      } else if (x1 < 1 || x2 < 1 || y1 > n || y2 > m) {
        cout << "NO" << endl;
      } else {
        vis[x1][y1] = 1;
        dfs(x1, y1, -1, -1);
        vis[x1][y1] = 0;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
      } 
    }
  }
  

  return 0;
}
