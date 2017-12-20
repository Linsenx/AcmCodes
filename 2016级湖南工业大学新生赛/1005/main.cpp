#include <bits/stdc++.h>
using namespace std;

int x;
int a[10010];
int b[10010];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> x) {
    int cnt = 0;
    int steps = 0;
    for (int i = 0; i < x; ++i) cin >> a[i];
    for (int j = 0; j < x; ++j) {
      cin >> b[j];
      if (a[j] == b[j]) b[j] = 0;
      else b[j] = 1, cnt++;
      //cout << b[j] << ' ';
    }
    //cout << endl;

    if (cnt % 2 == 0) {
      int flag = -1;
      for (int m = 0; m < x; ++m) {
        if (b[m] == 1) {
          if (flag == -1) {
            flag = m;
          } else {
            steps = steps + (m - flag);
            flag = -1;
          }
        }
      }
    } else {
      steps = -1;
    }
    cout << steps << endl;
  }

  return 0;
}
