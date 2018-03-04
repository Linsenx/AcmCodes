#include<cstdio>  
#include<cmath>  
#include<algorithm>  
#define maxn 100000  
using namespace std; 

struct tnode{double x,y;}q[maxn+100];  
	
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

double length(int i,int j)  
{  
	double x,y;  
	x=(q[i].x-q[j].x)*(q[i].x-q[j].x);  
	y=(q[i].y-q[j].y)*(q[i].y-q[j].y);  
	return sqrt(x+y);  
} 

int main()
{
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	
	int N;
	double minlen;
	
	while (scanf("%d", &N), N) {
		for (int i = 0; i < N; ++i) {
			scanf("%lf%lf", &q[i].x, &q[i].y);
		}
		
		sort(q, q + N, cmp1);  
		minlen = length(0, 1);
		for (int i = 1; i < N-1; ++i) {
			minlen = min(minlen, length(i, i+1));
		}    
		
		sort(q, q + N, cmp2);  
		for (int i = 0; i < N-1; ++i) {
			minlen = min(minlen, length(i, i+1));
		}	
		
		double xx = minlen/2;
		printf("%.2lf\n", xx);
	}
	return 0;
}
