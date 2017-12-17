#include <bits/stdc++.h>
using namespace std;

int getLen(int x) {
  int len = 1;
  while (pow(2,len) <= x) {
    ++len;
  }
  return len;
}


int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n;
  while (cin >> n) {
    int k[105];
    for (int i = 0; i < n+1; ++i) cin >> k[i];

    //1~2^n

    for (int j = 1; j <= pow(2,n); ++j) {
      int sum = 0;
      cout << j << ":";
      int len = getLen(j);
      for (int v = 0; v < len; ++v) {
        if ((j >> v) & 1) {
          //µÚlen-vÎ»
          sum += k[len-v-1];
        }
      }
    cout << sum << endl;
    }

  }
  return 0;
}
