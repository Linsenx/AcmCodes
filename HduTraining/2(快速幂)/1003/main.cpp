#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int MOD = 0;

struct matrix
{
  int row; //行
  int col; //列
  int m[35][35];
};

matrix ONE;

matrix mul(matrix a, matrix b)
{
  matrix ret;
  ret.row = a.row;
  ret.col = b.col;
  for(int i = 0; i < a.row; ++i) { 
    for(int j = 0; j < b.col; ++j) { 
      ret.m[i][j] = 0;
      for(int k = 0; k < a.col; ++k) {
        ret.m[i][j] = (ret.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
      }
    }
  }  
  return ret;
}

matrix add(matrix a, matrix b)
{
  matrix ret;
  ret.row = a.row;
  ret.col = a.col;
  for(int i = 0; i < ret.row; ++i) {
    for(int j = 0; j < ret.col; ++j) {
      ret.m[i][j] = (a.m[i][j] + b.m[i][j]) % MOD;
    }
  }
  return ret;
}

matrix powmul(matrix base, int n) {
  //构造单位阵
  matrix ans;
  //矩阵幂行列必须相等
  ans.col = ans.row = base.col; 
  for(int i = 0; i < ans.col; ++i) {
    for(int j = 0; j < ans.row; ++j) {
      if(i == j) ans.m[i][j] = 1;
      else ans.m[i][j] = 0;
    }
  }
  while(n) {
    if(n & 1) ans = mul(ans, base);
    base = mul(base, base);
    n >>= 1;
  }
  return ans;
}

matrix fun(matrix A, int k)
{
  if(k == 1) return A;
  if(k % 2 == 0) {
    matrix B = fun(A, k/2);
    return mul(add(ONE, powmul(A, k/2)), B);
  } else {
    matrix B = fun(A, k/2);
    matrix C = powmul(A, (k+1)/2);
    return add(mul(B, add(ONE, C)), C);
  }
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, k, m;
  matrix base, res;
  scanf("%d%d%d", &n, &k, &m);
  //构造单位阵
  ONE.col = ONE.row = n; 
  for(int i = 0; i < ONE.col; ++i) {
    for(int j = 0; j < ONE.row; ++j) {
      if(i == j) ONE.m[i][j] = 1;
      else ONE.m[i][j] = 0;
    }
  }
  
  MOD = m;
  base.col = base.row = n;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      scanf("%d", &base.m[i][j]);
    }
  }
  
  res = fun(base, k);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      printf("%d", res.m[i][j]);
      if(j < n - 1) printf(" ");
    }
    printf("\n");
  }

  return 0;
}
