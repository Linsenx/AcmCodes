#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int a, b, c;
  cin >> a >> b >> c;
  if (a <= 168) {
    cout << "CRASH " << a << endl;
  } else if (b <= 168) {
    cout << "CRASH " << b << endl;
  } else if (c <= 168) {
      cout << "CRASH " << c << endl;
  } else {
    cout << "NO CRASH" << endl;
  }

  return 0;
}