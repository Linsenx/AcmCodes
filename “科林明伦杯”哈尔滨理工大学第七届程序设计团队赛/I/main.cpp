#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int T, n, i, j;
int dp0[100100];
int dp1[100100];
int d[100100];
int p[100100];

int main()
{
  scanf("%d", &T);
  while (T--) {
    memset(d, 0, sizeof(d));
    memset(p, 0, sizeof(p));
    memset(dp0, 0, sizeof(dp0));
    memset(dp1, 0, sizeof(dp1));
    scanf("%d", &n);
    for (i = 0; i < n; ++i) scanf("%d", &d[i]);
    for (i = 0; i < n; ++i) scanf("%d", &p[i]);

    int max_ = 0;
    for (i = 0; i < n; ++i) {
      dp0[i] = p[i];
      dp1[i] = d[i];
      printf("%d=>%d\n", i, dp0[i]);
      int it = lower_bound(dp0, dp0+n, dp0[i]) - dp0;
      if (dp1[it] < dp1[i]) {
        dp0[i] = dp0[i] + dp0[it];
      }

      /*for (j = 0; j < i; ++j) {
        if (dp[j][1] < dp[i][1]) {
          dp[i][0] = dp[j][0] + p[i];
          dp[i][1] = dp[j][1];
        }
      }*/
      //cout << i << "=>" << dp[i][0] << endl;
      max_ = max(max_, dp0[i]);
    }
    printf("%d\n", max_);
  }


  return 0;
}
