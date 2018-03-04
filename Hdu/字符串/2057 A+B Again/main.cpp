#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  long long m, n, k;
  while(~scanf("%I64X%I64X", &m, &n))
  {
    k = m + n;
		m=m+n;
		if(m<0){m=-m;printf("-%I64X\n",m);}
    else printf("%I64X\n",m);
  }

  return 0;
}
