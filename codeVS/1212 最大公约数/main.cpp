#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
  while(b != 0) {
    int o = a % b;
    a = b;
    b = o;
  }
  return a;
}


int main()
{
  freopen("in.txt", "r", stdin);
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}
