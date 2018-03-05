#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n, kase;
  double x, y, s;
  while (cin >> n)
  {
    kase = 0;
    while (n--)
    {
      cin >> x >> y;
      s = 0.5 * 3.1415926 * (x*x + y*y);
      cout << "Property "<<++kase<<": This property will begin eroding in year "<<(int)(s/50)+1<<".\n";
    }
    cout << "END OF OUTPUT.\n";
  }

  return 0;
}
