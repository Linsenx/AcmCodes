#include <bits/stdc++.h>
using namespace std;

int nn(int n)
{
  int res = 1;
  for (int i = n; i >= 2; --i) res *= i;
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int a, b, c;
  while (cin >> a >> b) {
    if (a == -1 && b == -1) break;
    //c = c(a+b,a)
    c = nn(a+b)/(nn(a)*nn(b));
    if (a + b == c) cout << a << "+" << b << "=" << a+b << endl;
    else cout << a << "+" << b << "!=" << a+b << endl;
  }

  return 0;
}
