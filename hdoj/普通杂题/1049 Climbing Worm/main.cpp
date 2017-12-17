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
  while (cin >> a >> b >> c && a*b*c) {
    int d = ceil((double)(a-b)/(b-c));
    int t = d * 2 + 1;
    cout << t << endl;
  }

  return 0;
}
