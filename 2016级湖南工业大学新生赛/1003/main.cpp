#include <bits/stdc++.h>
using namespace std;

int want[20000];

int main()
{
  int n, x, sum;
  while (cin >> n) {
    sum = 0;
    memset(want, 0, 20000);
    for(int i = 0; i < n; ++i) {
      cin >> x;
      if (want[x] == 0) {
        want[x] = 1;
        sum += x;
      } else {
        for (int j = x; j < 20000; ++j) {
          if (want[j] == 0) {
            want[j] = 1;
            sum += j;
            break;
          }
        }
      }
    }
    cout << sum << endl;
  }

  return 0;
}
