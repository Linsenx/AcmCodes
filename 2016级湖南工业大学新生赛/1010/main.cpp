#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif


  int BN, N, M, k, gx, gy, bx, by;
  cin >> BN;
  while (BN--) {
    while (cin >> N >> M >> k) {
      char x;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          cin >> x;
          if (x == 'B') bx = i,by = j;
          else if (x == 'G') gx = i,gy = j;
        }
      }
      if (gx <= bx) {
        int dis = abs(bx-gx) + abs(by-gy);
        if (dis < k) cout << "YES" << endl;
        else cout << "NO" << endl;
      }
      else cout << "NO" << endl;
    }
  }

  return 0;
}
