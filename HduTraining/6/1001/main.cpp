#include <bits/stdc++.h>
using namespace std;

int sx, sy, n, m, min_step, G[15][15], step[15][15], ttime[15][15];

bool check(int x, int y)
{
  if (x >= n || x < 0 || y >= m || y < 0 || G[x][y] == 0) return false;
  else return true;
}

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x, int y, int costtime, int boomtime)
{
  if (boomtime == 0 || costtime >= min_step) return;
  if (G[x][y] == 4) boomtime = 6;
  if (G[x][y] == 3) {
    min_step = min(min_step, costtime);
    return;
  }
  
  if (step[x][y] <= costtime && boomtime <= ttime[x][y]) return;
  step[x][y] = costtime;
  ttime[x][y] = boomtime;
  
  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + dir[i][0];
    ny = y + dir[i][1];
    if (check(nx, ny)) {
      dfs(nx, ny, costtime + 1, boomtime - 1);
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
  
  int t;
  cin >> t;
  while (t--) {
    memset(G, 0, sizeof(G));
    memset(ttime, 0, sizeof(ttime));
    memset(step, 0, sizeof(step));
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> G[i][j];
      if (G[i][j] == 2) sx = i, sy = j;
    }
    min_step = 1e9;
    dfs(sx, sy, 0, 6);
    min_step == 1e9 ? cout << -1 << endl : cout << min_step << endl;
  } 

  return 0;
}
