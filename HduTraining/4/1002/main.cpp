#include <bits/stdc++.h>
using namespace std;

const int maxn = 1050;
int r, c;
double dp[maxn][maxn], p1[maxn][maxn], p2[maxn][maxn], p3[maxn][maxn];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (~scanf("%d%d", &r, &c)) {
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        dp[i][j] = 0;
        scanf("%lf%lf%lf", &p1[i][j], &p2[i][j], &p3[i][j]);
      }
      //dp[i][j] = p1[i][j]*dp[i][j] + p2[i][j]*dp[i][j+1] + p3[i][j]*dp[i+1][j] + 2;
      //dp[i][j]*(1-p1[i][j]) = p2[i][j]*dp[i][j+1] + p3[i][j]*dp[i+1][j] + 2;
      //dp[i][j] = (p2[i][j]*dp[i][j+1] + p3[i][j]*dp[i+1][j] + 2)/(1-p1[i][j]);
      
      for (int i = r-1; i >= 0; --i)
        for (int j = c-1; j >= 0; --j) {
          if (i == r-1 && j == c-1) continue;
          if (fabs(1.0-p1[i][j]) <= 1e-6) continue;
          //cout << "i:"<<i<<"j:"<<j<<"->" <<p1[i][j] << endl;
          dp[i][j] = (p2[i][j]*dp[i][j+1] + p3[i][j]*dp[i+1][j] + 2)/(1-p1[i][j]);
        }
      printf("%.3lf\n", dp[0][0]);
  }

  return 0;
}
