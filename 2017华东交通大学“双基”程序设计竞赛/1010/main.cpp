#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  // x >= 4294967296 -> 6
  string x;
  long long ll;
  while (cin >> x) {
    if (x.size() < 11) {
      ll = stoll(x);
      int j = 0;
      for (j = 0; ll != 1; ++j) {
        ll = floor(sqrt(ll));
      }
      cout << j << endl;
    }
    else if (x.size() == 11) {
      ll = stoll(x);
      if (ll < 4294967296) {
        cout << 5 << endl;
      } else {
        cout << "QAQ" << endl;
      }
    }
    else {
      cout << "QAQ" << endl;
    }
  }

  return 0;
}
