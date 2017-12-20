#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  string l;
  while (getline(cin, l)) {
    map<char, int> a;
    for (auto i : l) {
      a[i] ++;
    }
    for (char b = 'a'; b <= 'z'; ++b) {
      cout << b << ':' << a[b] << endl;
    }
    cout << endl;
  }

  return 0;
}
