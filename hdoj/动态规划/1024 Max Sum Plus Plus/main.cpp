#include <bits/stdc++.h>
using namespace std;

int m, n, t;
__int64 PREMAX, MAX;
__int64 a[1000010];
__int64 dp[2][1000010];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (~scanf("%d%d", &m, &n)) {
    t = 1;
    PREMAX = MAX = -111111111111;
    for (int c = 1; c <= n; ++c) scanf("%I64d", &a[c]);
    for (int d = 0; d <= n; ++d) dp[!t][d] = 0;

    for (int i = 1; i <= m; ++i, t=!t) {
      dp[t][i] = dp[!t][i-1] + a[i];
      PREMAX = dp[!t][i-1];
      MAX = dp[t][i];
      for(int j = i + 1; j <= n; ++j) {
        PREMAX = max(PREMAX, dp[!t][j-1]);
        dp[t][j] = max(dp[t][j-1], PREMAX) + a[j];
        if (i == m) {
          MAX = max(dp[t][j], MAX);
        }
      }
    }
    printf("%I64d\n", MAX);
  }


  return 0;
}
