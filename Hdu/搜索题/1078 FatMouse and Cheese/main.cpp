#include <bits/stdc++.h>
using namespace std;

int n, k;
int maxcheese;
int maps[305][305];
int DP[305][305];
int dire[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right , down , up , left

int dfs(int x, int y)
{
  int ans, newx, newy;
  
  if (DP[x][y]) return DP[x][y];
  
  DP[x][y] = maps[x][y];
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j <= k; ++j) {
      newx = x + dire[i][0]*j;
      newy = y + dire[i][1]*j;
      if (newx < 0 || newx >= n || newy < 0 || newy >= n) continue;
      if (maps[x][y] < maps[newx][newy]) {
        DP[x][y] = max(DP[x][y], dfs(newx, newy) + maps[x][y]);
      }
    }
  }
  
  return DP[x][y];
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n >> k && n != -1 && k != -1) {
    memset(DP, 0, sizeof(DP));
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < n; ++x) cin >> maps[y][x];
    }
    cout << dfs(0, 0) << endl;
  }

  return 0;
}
