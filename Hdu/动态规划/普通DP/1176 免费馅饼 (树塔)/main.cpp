#include <bits/stdc++.h>
using namespace std;

int n, dp[110000][20], tmax;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int x, t;
  while (scanf("%d", &n) != EOF && n) {
    memset(dp, 0, sizeof dp);
    tmax = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &x, &t);
      dp[t][x] ++;
      tmax = max(tmax, t);
    }

    for (int i = tmax-1; i >= 0; i--) {
      dp[i][0] += max(dp[i+1][1], dp[i+1][0]);
      for (int j = 1; j <= 10; j++) {
        dp[i][j] += max(max(dp[i+1][j-1], dp[i+1][j+1]), dp[i+1][j]);
      }
    }
    printf("%d\n", dp[0][5]);
  }

  return 0;
}
