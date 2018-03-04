#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n;
  while (cin >> n && n != 0) {
    int max_ = 0;
    string name, max_name;
    map<string, int> dao;
    for (int i = 0; i < n; ++i) {
      cin >> name;
      dao[name]++;
      if (dao[name] >= max_) {
        max_ = dao[name];
        max_name = name;
      }
    }
    cout << max_name << endl;
  }

  return 0;
}
