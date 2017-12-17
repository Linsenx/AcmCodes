#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int T, n;
  int M, m, x;
  cin >> T;
  while (T--) {
    M = 0;
    m = 9999999;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      M = max(M, x);
      m = min(m, x);
    }
    cout << M - m << endl;
  }

  return 0;
}
