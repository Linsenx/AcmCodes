#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int x;
  while (cin >> x && x != 0) {
    cout << (x & (-x)) << endl;
  }

  return 0;
}
