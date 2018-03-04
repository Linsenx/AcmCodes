#include<cstdio>  
#include<cmath>  
#include<algorithm>  
#define maxn 100000  
using namespace std; 

int N;
double minlen;
struct tnode {
  double x;
  double y;
} ppp[100100];

bool cmp1(tnode a,tnode b)  
{  
  if(a.x<b.x)return 1;  
  if(a.x>b.x)return 0;  
  return a.y<b.y;  
}  
  
bool cmp2(tnode a,tnode b)  
{  
  if(a.y<b.y)return 1;  
  if(a.y>b.y)return 0;  
  return a.x<b.x;  
} 

double getdis(int a, int b)
{
  double x, y;
  x = (ppp[a].x - ppp[b].x) * (ppp[a].x - ppp[b].x);
  y = (ppp[a].y - ppp[b].y) * (ppp[a].y - ppp[b].y);
  return sqrt(x+y);
}

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (scanf("%d", &N), N) {
    
    for (int i = 0; i < N; ++i) {
      scanf("%lf%lf", &ppp[i].x, &ppp[i].y);
    }
    
    sort(ppp, ppp + N, cmp1);  
    minlen = getdis(0, 1);
    for (int i = 1; i < N; ++i) {
      minlen = min(minlen, getdis(i, i+1));
    }    
    
    sort(ppp, ppp + N, cmp2);  
    for (int i = 0; i < N; ++i) {
      minlen = min(minlen, getdis(i, i+1));
    }
    
    double xx = minlen/2;
    printf("%.2lf\n", xx);
  }
  return 0;
}
