#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);
  
  int x, sum;
  while(cin >> x && x != 0) {
    sum = 1;
    for (int i = 1; i <= x; ++i) {
      sum += x - i;
      sum += (x - i) * (x - i - 1)/2;
    }
    cout << sum << endl;
  }

  return 0;
}
