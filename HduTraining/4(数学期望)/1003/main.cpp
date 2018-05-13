#include <bits/stdc++.h>
using namespace std;

const int maxn = 2020;
const double eps = 1e-5;
double c[maxn];
double pp[maxn];
double dp[3][maxn];

int main()
{
  ios::sync_with_stdio(false);
//  #ifdef ONLINE_JUDGE
//  #else
//    freopen("in.txt","r",stdin);
//  #endif
  
  int n, m, k;
  double p1, p2, p3, p4, p21, p31, p41;
  while (~(scanf( "%d%d%d%lf%lf%lf%lf", &n, &m, &k, &p1, &p2, &p3, &p4 ))) {    
    if (p4 < eps) {
      printf("0.00000\n");
      continue;
    }
    
    p21 = p2/(1.0-p1);
    p31 = p3/(1.0-p1);
    p41 = p4/(1.0-p1);
    c[1] = p41;
    pp[0] = 1.0;
    dp[1][1] = p41/(1.0-p21);
    for (int i = 1; i <= n; ++i) pp[i] = p21 * pp[i-1];
    
    for (int i = 2; i <= n; ++i) {      
      for (int j = 2; j <= k; ++j) c[j] = dp[1][j-1]*p31 + p41;
      for (int j = k + 1; j <= i; ++j) c[j] = dp[1][j-1]*p31;
      
      double rhs = c[1]*pp[i-1];
      for (int j = 2; j <= k; ++j) rhs += c[j]*pp[i-j];
      for (int j = k + 1; j <= i; ++j) rhs += c[j]*pp[i-j];
      
      dp[2][i] = rhs/(1.0-pp[i]);
      dp[2][1] = dp[2][i]*p21 + c[1];
      
      for (int j = 2; j < i; ++j) dp[2][j] = dp[2][j-1]*p21 + c[j];
      
      for (int j = 0; j <= n; ++j) {
        dp[1][j] = dp[2][j];
      }
    }
    printf("%.5lf\n", dp[1][m]);
  }

  return 0;
}
