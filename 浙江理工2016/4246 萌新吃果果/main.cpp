#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  string str;
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k >> str;
    
    int sum = 0;
    int lianxu = 0;
    char last = str[0];
    for (int i = 1; i < str.size(); ++i) {
      if ((str[i] != 'c' && last == str[i]) || (last == 'b' && str[i] == 'a') || (last == 'c' && str[i] == 'a')) {
        lianxu ++;
      } else {
        if (str[i] == 'b') {
          cout << str[i];
          sum ++;
        } else if (lianxu >= k) {
          cout << str[i];
          sum ++;
        }
      }
      last = str[i];
    }
    cout << n + sum << endl;
  }
  return 0;
}
