#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;
int n, m, q, sx, sy, ex, ey, flag, G[N][N], vis[N][N], dirs[N][N];

bool check(int x, int y)
{
  if (x >= 1 && x <= n && y >= 1 && y <= m && vis[x][y] == 0) {
    if (G[x][y] == 0) return true;
    else if (x == ex && y == ey) return true;
    else return false;
  } else return false;
}

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int x, int y, int turn)
{  
  if (x == ex && y == ey) {
    flag = 1; 
    return;
  }
  
  if (turn > 2) return;
  if (turn == 2 && ex != x && ey != y) return;
    
    
  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + dir[i][0];
    ny = y + dir[i][1];
    
    if (check(nx, ny)) {
      dirs[nx][ny] = i;
      
//      if (x == 4 && y == 2) printf("(%d,%d)<%d> -> (%d,%d)<%d> [%d]\n", x, y, dirs[x][y], nx, ny, dirs[nx][ny],  turn);
      
      int dd = 0;
      if (dirs[x][y] != -1) {
        if (dirs[nx][ny] != dirs[x][y])
          dd = 1;
      }
      
      vis[nx][ny] = 1;
      dfs(nx, ny, turn + dd);
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
  
  while (~scanf("%d%d", &n, &m)) {
    if (n == 0 && m == 0) break;
    
    memset(G, 0, sizeof(G));
    for (int i = 1 ; i <= n; ++i)
    for (int j = 1 ; j <= m; ++j)
      scanf("%d", &G[i][j]);
    
    scanf("%d", &q);
    while (q--) {
      scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
      flag = 0;
      if (G[sx][sy] != 0 && G[sx][sy] == G[ex][ey]) {
        memset(vis, 0, sizeof(vis));
        memset(dirs, 0, sizeof(dir));
        vis[sx][sy] = 1;
        dirs[sx][sy] = -1;
        dfs(sx, sy, 0);
      }
      flag == 1 ? printf("YES\n") : printf("NO\n");
    }
    
  }

  return 0;
}