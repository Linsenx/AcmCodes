#include<iostream>
using namespace std;

unsigned long long gcd(unsigned long long  a, unsigned long long  b)
{
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

int main()
{
  int T, n, i;
  unsigned long long x;
  unsigned long long ccd, first, min_;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    scanf("%lld", &x);
    min_ = first = ccd = x;
    for (i = 0; i < n - 1; ++i) {
      scanf("%lld", &x);
      min_ = min(min_, x);
      ccd = gcd(ccd, x);
    }

    if (min_ / ccd != 1) {
      printf("%lld\n", first);
    } else {
      unsigned long long res = first / ccd;
      printf("%lld\n", res);
    }
  }

  return 0;
}
