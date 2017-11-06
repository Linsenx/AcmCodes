#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  long long a, a0, b, kase, num[4];
  while (cin >> a >> b) {
    a0 = a % 10;
    num[0] = a0;
    for (int i = 1; i < 4; ++i) {
      num[i] = (num[i-1] * a) % 10;
    }
    kase = (b - 1) % 4;
    if (b == 0) cout << 1 << endl;
    else cout << num[kase] << endl;
  }

  return 0;
}
