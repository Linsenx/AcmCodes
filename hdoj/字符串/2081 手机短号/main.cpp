#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int n;
  string pn;
  cin >> n;
  while (n--) {
    pn.clear();
    cin >> pn;
    cout << 6;
    for (int i = pn.size()-5; i < pn.size(); ++i)
      cout << i;
    cout << endl;
  }

  return 0;
}
