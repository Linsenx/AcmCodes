#include <bits/stdc++.h>
using namespace std;

int fi(int x) {
  if (x == 1) return 1;
  if (x == 2) return 1;
  return fi(x - 1) + fi(x - 2);
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  cout << fi(n) << endl;
  return 0;
}
