#include <bits/stdc++.h>
using namespace std;

int solve(int x, int steps)
{
  if (x == 1) return steps;
  else if(x%2 != 0) x = 3*x + 1;
  else if(x%2 == 0) x = x / 2;
  solve(x, steps+1);
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int x, steps , T;
  cin >> T;
  while (T--) {
    cin >> x;
    cout << solve(x, 0) << endl;
  }

  return 0;
}
