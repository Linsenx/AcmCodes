#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int a, b, c, x;
  while (cin >> a >> b >> c) {
    x = (c-b)/a;
    cout << x << endl;
  }

  return 0;
}
