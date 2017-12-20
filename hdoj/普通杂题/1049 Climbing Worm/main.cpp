#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, u, d, h, t;
  while (cin >> n >> u >> d && n * u * d) {
    t = 1;
    h = u;
    while (h < n) {
      h += u;
      
      if (h < n) {
        h -= d;
      }
      t ++;
    }
    cout << t << endl;
  }

  return 0;
}
