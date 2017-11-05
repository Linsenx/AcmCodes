#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592653589793238462643383249901429;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int N, x, res;
  cin >> N;
  while (N--) {
    //斯特林公式 ——Stirling公式（取N阶乘近似值）
    //N! 位数
    cin >> x;
    res = log10(2*PI*x)/2 + x*log10(x/exp(1)) + 1;
    cout << res << endl;
  }

  return 0;
}
