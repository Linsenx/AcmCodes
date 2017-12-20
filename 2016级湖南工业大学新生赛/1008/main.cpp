#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  //X = (x+0) + (x+1) + (x+2) + ...... + (x+i-1)
  //X = x*i + (i-1)*i/2
  //x*i = X - (i-1)*i/2
  int x, k1, k2, cnt;
  while (cin >> n) {
    while (n--) {
      cnt = 0;
      cin >> x;
      for (int i = 2; (i-1)*i/2 < x; ++i) {
        k1 = (i-1)*i/2;
        k2 = x - k1;
        if (k2 == 0) break;
        else if(k2 % i == 0) cnt++;
      }
      if (cnt > 0) cout << cnt << endl;
      else cout << "I will not buy these figures.(好蓝瘦>_<香菇，我为什么要说射种袜)" << endl;

    }
  }
  return 0;
}
