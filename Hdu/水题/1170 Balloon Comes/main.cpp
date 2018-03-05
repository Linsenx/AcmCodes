#include <bits/stdc++.h>
using namespace std;

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n;
  char a;
  int x, y;
  while (scanf("%d", &n) != EOF)
  {
    getchar();
    for (int i = 0; i < n; ++i)
    {
      scanf("%c%d%d", &a, &x, &y);
      if (a == '+') printf("%d\n", x+y);
      else if (a == '-') printf("%d\n", x-y);
      else if (a == '*') printf("%d\n", x*y);
      else if (a == '/') {
        if (x%y != 0) printf("%.2f\n", 1.0*x/y);
        else printf("%d\n", x/y);
      }
      getchar();
    }
  }

  return 0;
}
