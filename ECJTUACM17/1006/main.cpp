#include <bits/stdc++.h>
using namespace std;

int T;
//0,1,2,3,4,5,6,7,8,9
int circule[10] = {1,0,0,0,0,0,1,0,2,1};

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> T) {
    for (int i = 0; i < T; ++i) {
      int sum = 0;
      string x;
      cin >> x;
      for (auto j : x) {
        sum += circule[j-'0'];
      }
      cout << sum << endl;
    }
  }
  
  return 0;
}
