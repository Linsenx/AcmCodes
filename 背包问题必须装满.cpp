#include<bits/stdc++.h>
using namespace std;

int T, N, V;
int w[1050];
int v[1050];
int dp[1050];

int main()
{
  cin >> T;

  while (T--) {
    fill(dp, dp + 1050, -10000);
    dp[0] = 0;
    cin >> N >> V;
    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int i = 1; i <= N; ++i) cin >> w[i];

    for (int i = 1; i <= N; ++i) {
      for (int j = V; j >= w[i]; --j) {
        if (dp[j-w[i]] != -100) {
          dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
      }

      for (int k = 1; k <= V; ++k) {
        printf("%6d", dp[k]);
      }
      cout << endl;
    }
    cout << dp[V] << endl;
  }


  return 0;
}
