#include <bits/stdc++.h>
using namespace std;

int start, min_start, max_number;

void solve(int x)
{
  start = -1;
  min_start = -1;
  max_number = -1;
  int j = 0, k = 0, max_ = 0;
  for (int i = 2; i*i < x; ++i) {
    if (x % i == 0) {
        j = x;
        k = i;
        max_ = 0;
        while (j % k == 0) {
          j = j/k;
          ++k;
          ++max_;
        }
        if (max_ > max_number) {
          start = i;
          max_number = max_;
        } else if (max_ == max_number && i < start) {
          min_start = i;
        }
    }
  }
  min_start = min_start == -1 ? start : min_start;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int x;
  while(cin >> x) {
    solve(x);
    for (int i = 0; i < max_number; ++i) {
      cout << min_start + i;
      if (i != max_number - 1) cout << '*';
    }
    cout << endl;
    //cout << min_start << '-' << max_number << endl;
  }

  return 0;
}
