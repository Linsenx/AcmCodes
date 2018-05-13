#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

const int MOD = 10000;

struct matrix
{
  int row; //行
  int col; //列
  int m[10][10];
};

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

matrix quick_pow(matrix base, int n) {
  //构造单位阵
  matrix ans;
  ans.col = ans.row = base.col; //矩阵幂行列必须相等
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

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  matrix base;
  base.row = base.col = 2;
  base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
  base.m[1][1] = 0;
  
  int n;
  while(scanf("%d", &n) != EOF && n != -1) {
    matrix res = quick_pow(base, n);
    printf("%d\n", res.m[0][1]);
  }

//  matrix a, b, res;
//  a.row = 4;
//  a.col = 3;
//  a.m[0][0]=5;a.m[0][1]=2;a.m[0][2]=4;
//  a.m[1][0]=3;a.m[1][1]=8;a.m[1][2]=2;
//  a.m[2][0]=6;a.m[2][1]=0;a.m[2][2]=4;	
//  a.m[3][0]=0;a.m[3][1]=1;a.m[3][2]=6;
//  
//  b.row = 3;
//  b.col = 2;
//  b.m[0][0]=2;b.m[0][1]=4;
//  b.m[1][0]=1;b.m[1][1]=3;
//  b.m[2][0]=3;b.m[2][1]=2;
//  
//  res = mul(a, b);
//  for(int i = 0; i < 4; ++i) {
//    for(int j = 0; j < 2; ++j) {
//      cout << res.m[i][j] << ',';
//    }
//    cout << endl;
//  }  

  return 0;
}
