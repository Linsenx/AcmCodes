#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  double j;
  double x;
  double sum;
  while (cin >> x && x != 0) {
    j = 2;
    sum = 0;
    for (j = 2; sum < x; ++j) {
      sum += 1/j;
    }
    cout << j-2 << " card(s)" << endl;
  }

  return 0;
}
