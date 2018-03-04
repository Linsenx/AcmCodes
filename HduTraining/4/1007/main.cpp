#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-12;
int vis[500];
bool free_x[500];  
double p[500], a[500][500], x[500];
int n, m, y, xx, d;

int sgn(double x)  
{  
  return (x>eps)-(x<-eps);  
}  

int gauss()  
{  
  int i, j, k;  
  int max_r;  
  int col;  
  double temp;  
  int free_x_num;  
  int free_index;  
  int equ = n,var = n;  
  col = 0;  
  memset(free_x,true,sizeof(free_x));  
  for (k = 0; k < equ && col < var; k++, col++)  
  {  
    max_r = k;  
    for (i = k + 1; i < equ; i++)  
    {  
      if (sgn(fabs(a[i][col]) - fabs(a[max_r][col]))>0) max_r = i;  
    }  
    if (max_r != k)  
    {  
      for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);  
    }  
    if (sgn(a[k][col]) == 0 )  
    {  
      k--; continue;  
    }  
    for (i = k + 1; i < equ; i++)  
    {  
      if (sgn(a[i][col])!=0)  
      {  
        double t = a[i][col] / a[k][col];  
        for (j = col; j < var + 1; j++)  
        {  
          a[i][j] = a[i][j] - a[k][j] * t;  
        }  
      }  
    }  
  }  
  for(i=k;i<equ;i++)  
  if(sgn(a[i][col])!=0) {return 0;}  
  if (k < var)  
  {  
    for (i = k - 1; i >= 0; i--)  
    {  
      free_x_num = 0;  
      for (j = 0; j < var; j++)  
      {  
        if ( sgn(a[i][j])!=0 && free_x[j]){  
          free_x_num++, free_index = j;  
        }  
      }  
      if(free_x_num>1)    continue;  
      temp = a[i][var];  
      for (j = 0; j < var; j++)  
      {  
        if (sgn(a[i][j])!=0 && j != free_index) temp -= a[i][j] * x[j];  
      }  
      x[free_index] = temp / a[i][free_index];  
      free_x[free_index] = 0;  
    }  
    return var - k;  
  }  
  
  for (i = var - 1; i >= 0; i--)  
  {  
    temp = a[i][var];  
    for (j = i + 1; j < var; j++)  
    {  
      if (sgn(a[i][j])!=0) temp -= a[i][j] * x[j];  
    }  
    x[i] = temp / a[i][i];  
  }  
  return 1;  
} 

void bfs()
{
  int v, next;
  queue<int> q;
  q.push(xx);
  vis[xx] = 1;
  
  while (!q.empty()) {
    v = q.front(); q.pop();
    for (int i = 1; i <= m; ++i) {
      next = (v + i) % n;
      if (sgn(p[i]) && vis[next] == 0) {
        vis[next] = 1;
        q.push(next);
      }
    }
  }
   
}

void build()
{
  int next;
  double sum = 0;
  for (int i = 1; i <= m; ++i)
    sum += i * p[i];
    
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; ++i) {
    a[i][i] = 1;
    
    if (!vis[i]) {
      continue;
    }
    
    if (i == y || i == (n - y) % n) {
      a[i][n] = 0;
      continue;
    }
    
    a[i][n] = sum;
    for (int k = 1; k <= m; ++k) {
      next = (i + k) % n;
      //*注意点：可能在1～m步内多次到达同一个next点，所以必须 -= 
      if(vis[next] == 1) a[i][next] -= p[k];
    }
  }
}

int main()
{
//  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(vis, 0, sizeof vis);
    scanf("%d%d%d%d%d",&n,&m,&y,&xx,&d);  
    for (int i = 1; i <= m; ++i) {
      int pk;
      scanf("%d", &pk);
      p[i] = pk*1.0/100;
    }
    
    if (y == xx) {
      printf("0.00\n");
      continue;
    }
    
    n = 2 * (n-1);
    if (d == 1) xx = (n - xx) % n;
    
    bfs();
    if (vis[y] == 0 && vis[(n-y)%n] == 0) {
      printf("Impossible !\n");
      continue;
    }
    
    build();
    
    if (!gauss()) {
      printf("Impossible !\n");
      continue;
    }
    printf("%.2lf\n", x[xx]);
    
  }

  return 0;
}
