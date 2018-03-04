#include<bits/stdc++.h>
#include<stdio.h>

int main()
{

  long long n, m, t1, t2, t3, t4;
  long long t_walk, t_ele, t_min;

  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  while(scanf("%lld%lld", &n, &m) != EOF) {
    scanf("%lld%lld%lld%lld", &t1, &t2, &t3, &t4);

    t_walk = 0;
    t_ele = 0;
    t_min = 0;

    t_walk = (n-1) * t4;
    t_ele = (n-1) * t1 + t2 + t3 + t2;
    t_ele += (std::max(n,m)-std::min(n,m))*t1;
    printf("%lld\n", std::min(t_walk, t_ele));
  }

  return 0;
}
