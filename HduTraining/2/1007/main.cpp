#include <bits/stdc++.h>
using namespace std;

int MOD = 10000;

struct matrix
{
  int row; //行
  int col; //列
  double m[210][210];
  
  matrix(void)
  {
    memset(m, 0, sizeof(m));
  };
  
  void clear()
  {
    memset(m, 0, sizeof(m));
  };
  
  matrix operator + (matrix &mat)
  {
    matrix ret;
    ret.row = row;
    ret.col = col;
    for(int i = 0; i < ret.row; ++i) {
      for(int j = 0; j < ret.col; ++j) {
        ret.m[i][j] = (m[i][j] + mat.m[i][j]);
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
          ret.m[i][j] = (ret.m[i][j] + m[i][k] * mat.m[k][j]);
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

matrix mat;
matrix species;

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, m, t;
  while (cin >> n >> m && n + m != 0) {
    mat.clear();
    species.clear();
    species.row = n;
    species.col = 1;
    mat.row = mat.col = n;
    //构造单位阵
    for (int i = 0; i < n; ++i) mat.m[i][i] = 1;
    
    for (int i = 0; i < n; ++i) cin >> species.m[i][0];
    cin >> t;
    for (int i = 0; i < t; ++i) {
      int ii, jj;
      double rate;
      cin >> ii >> jj >> rate;
      mat.m[jj][ii] = rate;
      mat.m[ii][ii] -= rate;
    }
    
    cout << (mat^(m-1)) << endl;
    matrix res = (mat^(m-1)) * species;
    
    printf("%.0lf\n", res.m[n-1][0]);
  }

  return 0;
}
