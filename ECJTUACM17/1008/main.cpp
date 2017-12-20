#include <bits/stdc++.h>
using namespace std;
int table[1000100];

int o7(int x)
{
  if (x % 7 == 0) {
    return 1;
  } else {
    //123
    while (x > 1) {
      int k = x % 10;
      x /= 10;
      if (k == 7) {
        return 1;
      }
    }
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  //table
  for (int i = 1; i <= 1000000; ++i) {
    if (o7(i)) table[i] = 1;
  }
  
  int T, N;
  unsigned long long sum;
  cin >> T;
  //while (cin >> T) {
    while (T--) {
      cin >> N;
      sum = 0;
      for (int i = 1; i <= N; ++i) {
        if (table[i] == 0) sum += (unsigned long long)i * i;
      }
      cout << sum << endl;
    }
  //}

  return 0;
}
