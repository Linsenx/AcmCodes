#include <bits/stdc++.h>
using namespace std;

int T, n, p;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  cin >> T;
  while (T--) {
    cin >> n >> p;
    int couldKilled = n - 3;
    if (couldKilled %2 == 1) cout << "LYF" << endl;
    else cout << "BH" << endl;
  }

  return 0;
}
