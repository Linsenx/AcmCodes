#include <bits/stdc++.h>
using namespace std;
map<int, int>times;

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int T, n, mtimes;
  int x;
  cin >> T;
  while (T--) {
    cin >> n;
    times.clear();
    mtimes = 1;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      times[x]++;
      mtimes = max(mtimes, times[x]);
    }

    map<int, int>::iterator it = times.begin();
    int flag = 0;
    while (it != times.end()) {
      if (it->second == mtimes) {
        if (flag != 0) cout << " ";
        cout << it->first;
        flag = 1;
      }
      it++;
    }
    if (T) cout << endl;
  }

  return 0;
}
