#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  //E(i)投出i次正面向上的期望天数
  //E(i) = p*(E(i-1)+1) + (1-p)*(E(i)+1)
  //E(i) = i/p
  //
  //F(i)投出i个正面向上期望花费
  //F(i) = p*(F(i-1) + 2*(E(i-1)+1)-1) + (1-p)(F(i) + 2*(E(i)+1)-1)

  double k, p, ans;
  while (cin >> k && k != 0) {
    cin >> p;
    ans = 0;
    for (int i = 1; i <= k; ++i) {
      ans = ans + ((2*i-p)/(p*p));
    }
    printf("%.3f %.3f\n", (k/p), ans);
  }
  

  return 0;
}
