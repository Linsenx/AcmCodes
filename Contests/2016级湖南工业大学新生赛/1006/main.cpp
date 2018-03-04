#include <bits/stdc++.h>
using namespace std;

int isprime(int x)
{
  for (int i = 2; i*i <= x; ++i) {
    if (x % i == 0) return 0;
  }
  return 1;
}

int gcd(int a, int b)
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

  int N, x, mutl, mutl_;
  while (cin >> N) {
    mutl = 0;
    mutl_ = 0;
    for (int i = 0; i < N; ++i) {
      cin >> x;
      if (isprime(x)) {
        if (mutl == 0) {
          mutl = x;
        } else {
          mutl = (mutl*x) / gcd(mutl, x);
        }
      }
      if (mutl_ == 0) {
        mutl_ = x;
      } else {
        mutl_ = (mutl_*x) / gcd(mutl_, x);
      }
    }

    if (mutl == mutl_) cout << "YES" << endl;
    else  cout << "NO" << endl;
  }

  return 0;
}
