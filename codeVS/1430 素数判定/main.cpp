#include <bits/stdc++.h>
using namespace std;

int isPrime(int x)
{
  int v = sqrt(x);
  for(int i = 2; i <= v; ++i) {
      if (x % i == 0) return 0;
  }
  return 1;
}


int main()
{
  freopen("in.txt", "r", stdin);
  int a;
  cin >> a;
  if (isPrime(a) == 1) {
      cout << "\\t" << endl;
  }
  else{
      cout << "\\n" << endl;
  }
  return 0;
}
