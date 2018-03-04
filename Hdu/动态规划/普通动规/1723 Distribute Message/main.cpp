#include <bits/stdc++.h>
using namespace std;

int N, M;
int dp[100];

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif


  while (scanf("%d%d", &N, &M) != EOF && N != 0 && M != 0) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (i - j <= M) {
          dp[i] += dp[j];
        }
      }
    }
    printf("%d\n", dp[N-1]);
  }


  return 0;
}
