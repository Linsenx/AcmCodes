#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1500];
ll dp[1500];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n;
  while (cin >> n && n != 0) {
    memset(a, 0, 1500);
    memset(dp, 0, 1500);
    for (int i = 0; i < n; ++i) cin >> a[i];

    dp[0] = a[0];
    ll __max = dp[0];
    for (int j = 1; j < n; ++j) {
      dp[j] = a[j];
      for (int k = 0; k < j; ++k) {
        if (a[k] < a[j]) dp[j] = max(dp[j], dp[k]+a[j]);
      }
      __max = max(__max, dp[j]);
    }

    cout << __max << endl;

  }

  return 0;
}
