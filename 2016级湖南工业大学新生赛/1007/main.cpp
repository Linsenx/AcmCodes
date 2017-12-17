#include <bits/stdc++.h>
using namespace std;

int N, n, kase;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int cnt;
  string str;
  while (cin >> N) {
    while (N--) {
      cnt = 0;
      cin >> n;
      map<string, int> names;
      for(int i = 0; i < n; ++i) {
        cin >> str;
        names[str]++;
        if (names[str] == 1) cnt++;
      }
      cout << "Case #" << (++kase) << ":" << endl;
      cout << cnt << endl;
      map<string, int>::iterator it;
      it = names.begin();
      while (it != names.end()) {
        cout << it->first << " " << it->second << endl;
        it ++;
      }
    }
  }

  return 0;
}
