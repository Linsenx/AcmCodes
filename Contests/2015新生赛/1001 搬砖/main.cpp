#include <bits/stdc++.h>
using namespace std;

int memo[10000005];

int solve(int x)
{
  if (x <= 2) return 0;
  if (memo[x] != 0) return memo[x];
  int d1, d2, sum;
  d1 = x / 2;
  d2 = x - d1;
  sum = solve(d1) + solve(d2) + max(d1,d2) - min(d1,d2);
  memo[x] = sum;
  return sum;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt","r",stdin);

  int n, x;
  cin >> n;
  while(n--) {
    cin >> x;
    cout << solve(x) << endl;
  }

  return 0;
}
