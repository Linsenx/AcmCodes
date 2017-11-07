#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

char mp[10][10];
int n, m, t;
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int sx, sy, dx, dy;
bool flag;

void dfs(int x, int y, int step)
{
  int nx, ny;
  if (flag) {
    return;
  }
  if (step > t) {
    return;
  }
  if ((t-step-abs(x-dx)-abs(y-dy))%2 == 1) {
    return;
  }
  if (x==dx && y == dy && step == t) {
    flag = true;
    return;
  }

  for (int i = 0; i < 4; i++) {
    nx = x + dir[i][1];
    ny = y + dir[i][0];
    if (mp[ny][nx] != 'X' && nx>=0&&nx<m&&ny>=0&&ny<n) {
      mp[ny][nx] = 'X';
      dfs(nx, ny, step+1);
      mp[ny][nx] = '.';
      if (flag) {
        return;
      }
    }
  }
}


int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (~scanf("%d%d%d", &n, &m, &t) && (m+n+t)) {
    int w = 0;
    memset(mp,'X',sizeof(mp));
    for (int ii = 0; ii < n; ++ii)
      scanf("%s", mp[ii]);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mp[i][j] == 'S') {
          sx = j;
          sy = i;
        }
        if (mp[i][j] == 'D') {
          dx = j;
          dy = i;
        }
        if (mp[i][j] == 'X')
          w++;
      }
    }

    if (n*m-w<t||(t-abs(sx-dx)-abs(sy-dy))%2 == 1||abs(sx-dx)+abs(sy-dy)>t) {
      printf("NO\n");
      continue;
    }

    flag = false;
    dfs(sx, sy, 0);
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}