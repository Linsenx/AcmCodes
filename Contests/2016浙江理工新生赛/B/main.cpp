#include <bits/stdc++.h>
using namespace std;

int T;
int n, k, Q;
int h[100100];
int maxlen;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  cin >> T;
  while (T--) {
    cin >> n >> k >> Q;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    for (int j = 0; j < Q; ++j) {
      maxlen = 0;
      int l, r, max_height, length = 1;
      cin >> l >> r;
      max_height = min(h[r], h[r-1]+k);
      for (int v = r - 1; v >= l; --v) {
        if (max_height-k*length > 0 && h[v] >= max_height-k*length) {
          ++length;
        } else {
          maxlen = max(maxlen, length);
          length = 1;
          max_height = min(h[r], h[r-1]+k);
        }
      }
      maxlen = max(maxlen, length);
      cout << maxlen << endl;
    }
  }


  return 0;
}
