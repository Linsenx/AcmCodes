#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int num, flag;
  while(cin >> num) {
    flag = 0;
    for (int i = 1; !flag && i <= 100; ++i) {
      for (int j = 1; !flag && j <= 100; ++j) {
        for (int k = 1; !flag && k <= 100; ++k) {
          if (i*i + j*j + k*k == num) {
            flag = 1;
            cout << i << " " << j << " " << k << endl;
          }
        }
      }
    }
  }

  return 0;
}
