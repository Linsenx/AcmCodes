#include <bits/stdc++.h>
#define pi 3.1415927
#define rate (12*5280);
using namespace std;

int r, kase;
float d, t, dis, speed;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> d >> r >> t && r != 0) {
    dis = (2 * pi * (d / 2) * r) / rate;
    speed = (dis / t) * 3600;
    printf("Trip #%d: %.2lf %.2lf\n", ++kase, dis, speed);
  }

  return 0;
}
