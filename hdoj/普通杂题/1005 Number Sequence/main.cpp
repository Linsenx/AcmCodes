#include <bits/stdc++.h>
using namespace std;

int A, B, n, fib[50], kase;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  fib[1] = 1;
  fib[2] = 1;

  while (cin >> A >> B >> n && A != 0 && B != 0 && n != 0) {
    for (int i = 3; i <= 48; ++i) {
      fib[i] = (A*fib[i-1] + B*fib[i-2])%7;
    }
    kase = n % 48;
    cout << fib[kase] << endl;
  }

  return 0;
}
