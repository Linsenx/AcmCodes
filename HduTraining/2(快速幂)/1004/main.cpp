#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int MOD = 0;

struct matrix
{
  int row; //行
  int col; //列
  int m[5][5];
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

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int F[5];
  F[0] = 0;F[1] = 2;F[2] = 4;F[3] = 6;F[4] = 9;
  matrix MF;
  MF.row = 4;
  MF.col = 1;
  MF.m[0][0] = F[4];
  MF.m[1][0] = F[3];
  MF.m[2][0] = F[2];
  MF.m[3][0] = F[1];
  
  matrix k;
  k.row = k.col = 4;
  k.m[0][0]=1;k.m[0][1]=0;k.m[0][2]=1;k.m[0][3]=1;
  k.m[1][0]=1;k.m[1][1]=0;k.m[1][2]=0;k.m[1][3]=0;
  k.m[2][0]=0;k.m[2][1]=1;k.m[2][2]=0;k.m[2][3]=0;
  k.m[3][0]=0;k.m[3][1]=0;k.m[3][2]=1;k.m[3][3]=0;
  
  int L;
  while(cin >> L >> MOD) {
    if(L <= 4) {
      cout << (F[L] % MOD) << endl;
    } else {
      matrix res = mul(powmul(k, L - 4), MF);
      cout << res.m[0][0] << endl;
    }
  }

  return 0;
}
