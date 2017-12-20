#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int T, n, x;
  int M, m;
	while (cin >> T) {
    while (T--) {
      cin >> n;
      M = -INF;
      m = INF;
      for (int i = 0; i < n; ++i) {
        cin >> x;
        M = max(M, x);
        m = min(m, x);
      }
      cout << M - m << endl;
    }
	}

  return 0;
}
