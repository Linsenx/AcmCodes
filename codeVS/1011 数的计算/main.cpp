#include <bits/stdc++.h>
using namespace std;

int fd(int x)
{
  int sum = 1;
  for (int i = 1; i <= x / 2; ++i) {
    sum += fd(i);
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);
  int x;
  cin >> x;
  cout << fd(x) << endl;
  return 0;
}
