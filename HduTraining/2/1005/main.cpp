#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int MOD = 10000;

struct matrix
{
  int row; //行
  int col; //列
  int m[10][10];
  
  matrix operator + (matrix &mat)
  {
    matrix ret;
    ret.row = row;
    ret.col = col;
    for(int i = 0; i < ret.row; ++i) {
      for(int j = 0; j < ret.col; ++j) {
        ret.m[i][j] = (m[i][j] + mat.m[i][j]) % MOD;
      }
    }
    return ret;
  };
  
  matrix operator * (matrix &mat)
  {
    matrix ret;
    ret.row = row;
    ret.col = mat.col;
    for(int i = 0; i < row; ++i) { 
      for(int j = 0; j < mat.col; ++j) { 
        ret.m[i][j] = 0;
        for(int k = 0; k < col; ++k) {
          ret.m[i][j] = (ret.m[i][j] + m[i][k] * mat.m[k][j]) % MOD;
        }
      }
    }  
    return ret;
  };
  
  matrix operator ^ (int n) 
  {
    //构造单位阵
    matrix ans, base;
    memcpy(&base, this, sizeof(base));
    //矩阵幂行列必须相等
    ans.col = ans.row = col; 
    for(int i = 0; i < ans.col; ++i) {
      for(int j = 0; j < ans.row; ++j) {
        if(i == j) ans.m[i][j] = 1;
        else ans.m[i][j] = 0;
      }
    }
    while(n) {
      if(n & 1) ans = ans * base;
      base = base * base;
      n >>= 1;
    }
    return ans;
  };
  
  friend ostream& operator<<(ostream& out,const matrix& mat)
  {
    for(int i = 0; i < mat.row; i++)
    {
      for(int j = 0; j < mat.col; j++)
      {
        out << mat.m[i][j] << ' ';
      }
      out << endl;
    }
    return out;
  };
};

matrix ONE;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  matrix mat_k, mat_f;
  mat_k.row = mat_k.col = 10;
  //for(int i = 0; i < 10; i++) mat_k.m[0][i] = 1;
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 10; ++j) {
      if(i == j) mat_k.m[i+1][j] = 1;
      else mat_k.m[i+1][j] = 0;
    }
  }
  
  mat_f.col = 1;
  mat_f.row = 10;
  for(int i = 0; i < 10; ++i) mat_f.m[i][0] = 9-i;
  
  int k;
  while(cin >> k >> MOD) {
    for(int i = 0; i < 10; ++i) cin >> mat_k.m[0][i];
    if(k < 10) cout << k << endl;
    else {
      matrix res;
      res = (mat_k^(k-9)) * mat_f;
      cout << res.m[0][0] << endl;
    }
  }

  return 0;
}
