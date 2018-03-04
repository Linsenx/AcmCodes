#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

const int MOD = 9973;

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
  
  int T, n, k;
  cin >> T;
  while(T--) {
    cin >> n >> k;
    matrix base;
    base.row = base.col = n;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        cin >> base.m[i][j];
      }
    }
    matrix res = quick_pow(base, k);
    int tr = 0;
    for(int j = 0; j < n; ++j) {
      tr = (tr + res.m[j][j]) % MOD;
    }
    cout << tr << endl;
  }

  return 0;
}
