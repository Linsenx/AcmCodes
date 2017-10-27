#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  //freopen("in.txt", "r", stdin);
  int x, j;
  while (cin >> x && x > 0) {
    j = x + (int)sqrt(x);
    while (j-(int)sqrt(j) != x) {
      cout << "MOVE TO:" << j << endl;
      j = x + (int)sqrt(j);
    }
    cout << j << endl;
  }
  return 0;
}
