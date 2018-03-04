#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int k;
  while (cin >> k) {
    int n = 1;
    double sn = 1;
    while (sn <= k) {
      n ++;
      sn = sn + (double)1/n;
    }
    cout << n << endl;
  }

  return 0;
}
