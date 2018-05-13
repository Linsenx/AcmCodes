
/* 
题意：一个人在数轴上来回走，以pi的概率走i步i∈[1, m]，给定n（数轴长度），m， 
e（终点），s（起点），d（方向），求从s走到e经过的点数期望. 
题意真是晦涩难懂，误导了我好久，纠结，痛苦。 
设E[x]是人从x走到e经过点数的期望值，显然对于终点有：E[e] = 0 
n个点翻过去（除了头尾两个点）变为2*(n-1)个点 
例如：6个点：012345  --->  0123454321 
那么显然，从5开始向右走其实就是相当于往回走 
然后方向就由两个状态转化成一个状态的，然后每个点就是只有一种状态了，对每个点建立方程高斯消元即可 
bfs判断是否可以到达终点 
建立方程： 
E[i]=E[i+1]*p1+E[i+2]*p2+……E[i+m]*pm+1*p[1]+2*p[2]……m*p[m] 
*/  
#include<iostream>  
#include<cstdlib>  
#include<stdio.h>  
#include<math.h>  
#include<queue>  
#include<memory.h>  
using namespace std;  
int n,m,y,xx,d;  
double p[105];  
bool vis[210];  
double a[210][210];  
const double eps = 1e-12;  
double x[230];  
bool free_x[230];  
void debug()  
{  
	for(int i=0;i<n;i++)  
	for(int j=0;j<=n;j++)  
	{  
		printf("%.2lf ",a[i][j]);  
		if(j==n) puts("");  
	}  
}  
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
int bfs()  
{  
	queue<int>qiqi;  
	qiqi.push(xx);  
	vis[xx]=true;  
	while(!qiqi.empty())  
	{  
		int u=qiqi.front();  
		qiqi.pop();  
		for(int i=1;i<=m;i++)  
		{  
			int v=(u+i)%n;  
			if(sgn(p[i])&&vis[v]==false)  
			{  
				vis[v]=true;  
				qiqi.push(v);  
			}  
		}  
	}  
	if(vis[y]||vis[(n-y)%n]) return 1;  
	else return 0;  
}  
void build()  
{  
		int i,j;  
		double sum = 0;  
		for (i = 1; i <=m;i++)  
		sum += p[i]*i;  
		memset(a, 0, sizeof a);  
		for (i = 0; i < n; ++i)  
		{  
			a[i][i] = 1;  
			if (!vis[i])  
			{  
				a[i][n] = 1e9;  
				continue;  
			}  
			if (i==y||i==(n-y)%n)  
			{  
				a[i][n] = 0;  
				continue;  
			}  
			a[i][n] = sum;  
			int now = i;  
			for (j = 1; j <=m; ++j)  
			{  
				now++;  
				if (now==n) now = 0;  
				a[i][now] -= p[j];  
			}  
		}  
}  
int main()  
{  
	freopen("in.txt","r",stdin);
	int t;  
	scanf("%d",&t);  
	while(t--)  
	{  
		scanf("%d%d%d%d%d",&n,&m,&y,&xx,&d);  
		for(int i=1;i<=m;i++)  
		{  
			int g;  
			scanf("%d",&g);  
			p[i]=1.0*g/100;  
		}  
		if(y==xx) {puts("0.00");continue;}  
		n=2*(n-1);  
		if(d>0) xx=(n-xx)%n;  
		memset(vis,false,sizeof(vis));  
		if(!bfs()) {puts("Impossible !");continue;}  
		build();  
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n + 1; ++j) {
				printf("%lf ", a[i][j]);
			}
			printf("\n");
		}
		//debug();  
		int uu=gauss();  
		if(uu==0)  {puts("Impossible !");continue;}  
		printf("%.2lf\n",x[xx]);  
	}  
}  