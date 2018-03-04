#include <bits/stdc++.h>
using namespace std;

struct point 
{
  int x;
  int y;
};

const double eps=1e-12;  
const int maxn = 250;
int n, m, sx, sy;
queue<point> q;
int flag[maxn][maxn];
char mp[20][20];

bool free_x[maxn];  
double x[maxn], a[maxn][maxn];

int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b)
{
  return a/gcd(a, b)*b;
}

int sgn(double x)  
{  
  return (x>eps)-(x<-eps);  
}  

// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int gauss(int equ, int var)
{
  int row = 0; //当前处理的行
  int col = 0; //当前处理的列
  int row_m = 0; //当前列数值最大的行
  double temp;
  int free_x_num;  
  int free_index;  
  fill(x, x + var, 0);
  memset(free_x, true, sizeof(free_x));
  
  for (row = 0; row < equ && col < var; ++row, ++col) 
  {
    row_m = row;
    for (int i = row + 1; i < equ; ++i)
    {
      if (fabs(a[i][col]) - fabs(a[row_m][col]) > 0) row_m = i;
    }
    if (row_m != row)
    {
      for (int j = 0; j < var + 1; ++j) swap(a[row_m][j], a[row][j]);
    }
    
    if (sgn(a[row][col]) == 0)
    {
      row--;
      continue;
    }
    
    for (int i = row + 1; i < equ; ++i)
    {
      if (sgn(a[i][col]) != 0)
      {
//        int flag = 1;
//        int LCM = lcm(abs(a[row][col]), abs(a[i][col]));
//        int pa = LCM/abs(a[row][col]);
//        int pb = LCM/abs(a[i][col]);
//        if (a[row][col] * a[i][col] < 0) flag = -1;
        double temp = a[i][col] / a[row][col]; 
        for (int j = col; j < var + 1; ++j)
        {
          a[i][j] = a[i][j] - a[row][j] * temp;
        }
      }
    }
  }
  //每当一行出现系数全为0，row就在equ的基础上减1
  //row = equ - 自由元个数
  
  //系数为0, 常数项不为0 (无解)
  for (int i = row; i < equ; ++i)
  {
    if (sgn(a[i][var]) != 0) return -1;
  }
  
  //自由元个数 
  if (row < var)
  {
    for(int i=row-1;i>=0;i--)  
    {  
      free_x_num=0;  
      for(int j=0;j<var;j++)  
      {  
        if (sgn(a[i][j])!=0&&free_x[j])  
          free_x_num++,free_index=j;  
      }  
      if(free_x_num>1) continue;  
      temp=a[i][var];  
      for(int j=0;j<var;j++)  
      {  
        if(sgn(a[i][j])!=0&&j!=free_index)  
          temp-=a[i][j]*x[j];  
      }  
      x[free_index]=temp/a[i][free_index];  
      free_x[free_index]=0;  
    }  
    return var-row; 
  }
  
  for (int i = var - 1; i >= 0; --i) 
  {
    double C = a[i][var]; //常数项
    for (int j = i + 1; j < var; ++j) C -= x[j] * a[i][j];
    //if (C % a[i][i] != 0) return -2; //不能整除，有浮点数解
    x[i] = C / a[i][i];
  } 
  return 1;
}

bool isok(int i, int j)
{
  if (i >= 0 && i < n && j >=0 && j < m && mp[i][j] != '#')
    return true;
  return false;
}

void bfs()
{
  point np, aa;
  while (!q.empty())
  {
    aa = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      np.x = aa.x + dir[i][0];
      np.y = aa.y + dir[i][1];
      if (isok(np.x, np.y) && flag[np.x][np.y] == 0)
      {
        q.push(np);
        flag[np.x][np.y] = 1;
      }
    }
  }
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  //Debug();
  while (~scanf("%d%d", &n, &m)) 
  {
    getchar();
    while (!q.empty())
      q.pop();
    memset(a, 0, sizeof(a));
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%c", &mp[i][j]);
        //cout << mp[i][j];
        if (mp[i][j] == '#') {
          continue;
        } else if (mp[i][j] == '$') {
          point p;
          p.x = i; p.y = j;
          flag[i][j] = 1;
          q.push(p);
        } else if (mp[i][j] == '@') {
          sx = i; sy = j;
        }
      }
      getchar();
    }
      bfs();
      
      for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) {
          if (mp[i][j] == '.' || mp[i][j] == '@') {
            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
              int nx = i + dir[k][0];
              int ny = j + dir[k][1];
              if (isok(nx, ny) && flag[nx][ny]) {
                cnt++;
                a[i*m+j][nx*m+ny] = -1;
              }
            }
            a[i*m+j][i*m+j] = cnt;
            a[i*m+j][n*m] = cnt;
          }
          else if (mp[i][j] == '$') {
            a[i*m+j][n*m] = 0;  
            a[i*m+j][i*m+j] = 1;
          }
        }
        
        int final = gauss(n*m, n*m);
        if (flag[sx][sy] && final) {
          printf("%.6lf\n", x[sx*m+sy]);
        } else {
          printf("-1\n");
        }
  }

  return 0;
}
