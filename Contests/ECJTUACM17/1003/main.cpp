#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  unsigned long long x, v;
  int k;
  while (cin >> x) {
    k = 1;
    //2^2 < 5 < 2^3
    while (x >= (unsigned long long)pow(2,k)) {
      k ++;
    }

    int cnt = 0;
    for (int j = 0; j < k; ++j) {
      if ((x >> j) & 1) cnt ++;
    }
    cout << cnt << endl;
  }

  return 0;
}
