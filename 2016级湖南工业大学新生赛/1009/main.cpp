#include <bits/stdc++.h>
using namespace std;

int l[4];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int flag = 0;
  while (cin >> l[0] >> l[1] >> l[2] >> l[3] && (l[0]+l[1]+l[2]+l[3]) > 0) {
    sort(l, l+4);
    if (l[0]+l[1]+l[2] > l[3] && (l[0]*l[1]*l[2]*l[3])) {
      cout<< "Yeah!I get a Yaodaoji!!" << endl;
    } else {
      cout << "Oh!No!I want to uninstall the game!!" << endl;
    }
  }

  return 0;
}
