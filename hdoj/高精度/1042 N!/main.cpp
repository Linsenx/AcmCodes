#include <bits/stdc++.h>
using namespace std;

int num[40000];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int len, count;
  string n;
  while(cin >> n) {
    count = 0;
    memset(num, 0, 40000);
    // input the n to the array
    len = n.size();
    for (int i = 0; i < len; ++i)
      num[len - 1 - i] = (int)(n[i] - '0');
    
    // run N!
    for (int j = 0; j < n - 1; j++) {
      for (int k = 0; k < len; ++k) {
        num[k] = num[k] * n;
      }
      for (int k = 0; k < len; ++k) {
        num[k] %= 10;
      }
    }
  }

  return 0;
}
