#include <bits/stdc++.h>
using namespace std;

int MOD = 10000;

struct matrix
{
  int row; //行
  int col; //列
  int m[100][100];
  
  matrix(void)
  {
    memset(m, 0, sizeof(m));
  }
  
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

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int t, n, m, q, p, x1, y1, x2, y2, x3, y3, x4, y4;
  scanf("%d", &t);
  getchar();
  while (t--) {
    scanf("%d%d", &m, &n);
    matrix mat;
    mat.row = m*n;
    mat.col = m*n;
    getchar();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        //printf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))\n", x1, y1, x2, y2, x3, y3, x4, y4);
        getchar();
        x1--;y1--;x2--;y2--;
        x3--;y3--;x4--;y4--;
        mat.m[i*n+j][x1*n+y1] = 1;
        mat.m[i*n+j][x2*n+y2] = 1;
        mat.m[i*n+j][x3*n+y3] = 1;
        mat.m[i*n+j][x4*n+y4] = 1;
      }
    }    
    for (int i = 0; i < m*n; ++i)
      mat.m[m*n-1][i] = 0;
    
    scanf("%d", &q);
    getchar();
    while(q--) {
      scanf("%d", &p);
      if (p == 0) {
        if (n == 1 && m == 1) printf("True\n");  
        else printf("False\n");  
        continue;  
      }
      
      matrix ans = mat^p;
      if (ans.m[0][m*n-1] == 0) {
        printf("False\n");
      } else {
        unsigned long long sum = 0;
        for(int j = 0; j < n*m-1; ++j)
          sum = sum + ans.m[0][j]; 
        if (sum > 0) printf("Maybe\n");
        else printf("True\n");
      }
    }
    printf("\n");
  }

  return 0;
}
