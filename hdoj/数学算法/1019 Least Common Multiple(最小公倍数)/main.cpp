#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
  return b == 0 ? a : gcd(b, a%b);
}


int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  long long N, n, LCM;
  cin >> N;
  while (N--) {
    cin >> n;
    long long nums[n];
    for(long long i = 0; i < n; ++i) cin >> nums[i];

    //最小公倍数 = a*b / gcd(a, b)
    if (n > 1) {
      LCM = (nums[0] * nums[1]) / gcd(nums[0], nums[1]);
      for(long long j = 1; j < n; ++j) {
        LCM = (LCM * nums[j]) / gcd(LCM, nums[j]);
      }
    }
    else {
      LCM = nums[0];
    }
    cout << LCM << endl;
  }


  return 0;
}
