#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
  while(b!=0)
  {
    int o = a%b;
    a = b;
    b = o;
  }
  return a;
}

int main() {
  int a, b;
  cin >> a >> b;
  int v = a*b;
  int s = (int)sqrt(v);
  int n = 0;
  for (int i = 1; i <= s; i++) {
    if ((v%i == 0) && (gcd(v/i, i)==a)) {
      n++;
    }
  }
  cout << n*2 << endl;
  return 0;

}

