#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  long long a,b,c,ccd;
  int m, n, k;
  while (cin >> m >> n >> k) {
    a = m;
    b = m;
    c = 2;
    for (int i = 0; i < k-1; ++i) c *= 2;
    b += n*c;
    ccd = __gcd(a,b);
    a /= ccd;
    b /= ccd;
    cout << a << '/' << b << endl;
  }

  return 0;
}
