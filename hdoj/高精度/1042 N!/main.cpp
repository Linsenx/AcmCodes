#include <bits/stdc++.h>
using namespace std;

int num[50000];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int len, count;
  string n;
  int nn;
  while(cin >> n) {
    nn = stoi(n);
    memset(num, 0, 40000);
    // input the n to the array
    len = n.size();
    for (int i = 0; i < len; ++i)
      num[len - 1 - i] = (int)(n[i] - '0');
    
    // run N!
    int k = 0; //进位
    for (int m = 1; m < nn; ++m) {
      for (int j = 0; j < len; j++) {
        num[j] = num[j] * m + k;
        k = num[j] / 10;
        num[j] = num[j] % 10;
      }
      while (k > 0) {
        num[len++] = k % 10;
        k /= 10;
      }
    }
    
    if (nn == 0) num[0] = 1;

    for (int mm = len - 1; mm >= 0; --mm) {
      cout << num[mm];
    }
    
        cout << endl;
  }

  return 0;
}
