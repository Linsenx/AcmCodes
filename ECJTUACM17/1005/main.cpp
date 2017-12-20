#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int len;
  while (cin >> len && len != 0) {
    int sum = 0;
    while (len >= 17) {
      sum ++;
      len -= 17;
    }
    if (len >= 12) sum ++;
    if (sum == 45) cout << "baka" << endl;
    else if (sum >= 12) cout << "Congratulations" << endl;
    else cout << "anatawayoihitodesu" << endl;
  } 
  
  return 0;
}
