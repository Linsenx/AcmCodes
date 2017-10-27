#include <bits/stdc++.h>
using namespace std;
int memo[1000];

int df(int x)
{
  if (x >= 0) return 5;
  else {
    if (memo[abs(x)] != 0) return memo[abs(x)];
    memo[abs(x)] = df(x+1) + df(x+2) + 1;
    return memo[abs(x)];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);
  memset(memo, 0, 1000);
  int n;
  cin >> n;
  cout << df(n) << endl;
  return 0;
}
