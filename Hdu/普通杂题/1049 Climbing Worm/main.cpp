#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
<<<<<<< HEAD
  
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
=======

  int a, b, c;
  while (cin >> a >> b >> c && a*b*c) {
    int d = ceil((double)(a-b)/(b-c));
    int t = d * 2 + 1;
>>>>>>> dbbd7cf70e1df7bd63439ae0cc5a7d3e33561bb5
    cout << t << endl;
  }

  return 0;
}
