#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  unsigned long long n, x;
  unsigned long long j = -1;
  while (cin >> n) {
    j = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      j = j == 0 ? x : j ^ x;
    }
    cout << j << endl;
  }
  return 0;
}
