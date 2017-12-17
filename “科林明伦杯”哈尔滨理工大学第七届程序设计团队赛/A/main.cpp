#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  //ios::sync_with_stdio(false);
  freopen("in.txt","r",stdin);

  int T, kase;
  int x, i, j, k, q;
  kase = 0;
  cin >> T;
  while (scanf("%d%d", &k, &q) != EOF) {
    printf("Case #%d:\n", ++kase);
    for(j = 0; j < q; ++j) {
      int a = k;
      int b = 0;
      int c = 0;
      for (i = 0; i < k; ++i) {
        scanf("%d", &x);
        b += x;
        c += x*x;
      }
      b *= 2;
      double res = sqrt((4*a*c-b*b)/(4*a))/2;
      printf("%.4lf\n", res);
    }
  }

  return 0;
}
