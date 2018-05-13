#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int n = 1010, mp[maxn][maxn], data[maxn][maxn], kase;

int lowbit(int x)
{
  return x & (-x);
}

void add(int x, int y, int num)
{
  for (int i = x; i < n; i+=lowbit(i)) {
    for (int j = y; j < n; j+=lowbit(j)) {
      data[i][j] += num;
    }
  }
}

int sum(int x, int y)
{
  int ans = 0;
  for (int i = x; i > 0; i-=lowbit(i)) {
    for (int j = y; j > 0; j-=lowbit(j)) {
      ans += data[i][j];
    }
  }
  return ans;
}

int query(int x1, int y1, int x2, int y2)
{
  return sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
}

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int test, qs;
  char cmd;
  int x1, y1, x2, y2, v;
  scanf("%d", &test);
  while (test--) {
    printf("Case %d:\n", ++kase);
    memset(data, 0, sizeof(data));
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        mp[i][j] = 1;
        add(i, j, 1);
      }
    }
    scanf("%d", &qs);
    while (qs--) {
      getchar();
      scanf("%c", &cmd);
      if (cmd == 'S') {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int nx1, ny1, nx2, ny2;
        nx1 = min(x1, x2);
        ny1 = min(y1, y2);
        nx2 = max(x1, x2);
        ny2 = max(y1, y2);
        nx1++;ny1++;nx2++;ny2++;
        printf("%d\n", query(nx1, ny1, nx2, ny2));
      } else if (cmd == 'A') {
        scanf("%d%d%d", &x1, &y1, &v);
        x1++;y1++;
        add(x1, y1, v);
        mp[x1][y1] += v;
      } else if (cmd == 'D') {
        scanf("%d%d%d", &x1, &y1, &v);
        x1++;y1++;
        int mvaway = min(mp[x1][y1], v);
        add(x1, y1, -mvaway);
        mp[x1][y1] -= mvaway;
      } else if (cmd == 'M') {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
        x1++;y1++;x2++;y2++;
        int mvaway = min(mp[x1][y1], v);
        add(x1, y1, -mvaway);
        add(x2, y2, mvaway);
        mp[x1][y1] -= mvaway;
        mp[x2][y2] += mvaway;
      }
    }
  }

  return 0;
}
