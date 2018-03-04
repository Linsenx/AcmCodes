#include <bits/stdc++.h>
using namespace std;

int q, L, t, T;
int b1, b2;
int v1, v2;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  cin >> q;
  while (cin >> L >> t >> T) {
    b1 = 0;
    v1 = 1;
    b2 = L;
    v2 = -1;
    //先计算b1的位置
    for (int i = 0; i < T; ++i) {
      b1 += v1;
      if (b1 == 0 || b1 == L) v1 *= -1;
    }
    //再计算b2的位置
    for (int i = 0; i < T - t; ++i) {
      b2 += v2;
      if (b2 == 0 || b2 == L) v2 *= -1;
    }
    int dis = abs(b1-b2);
    cout << dis << endl;
  }

  return 0;
}
