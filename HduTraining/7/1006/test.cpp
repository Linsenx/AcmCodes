#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int MAXN = 510;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
	for(int v = 0; v < vN;v++)
		if(g[u][v] && !used[v])
		{
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] = u;
				return true;
			}
		}
	return false;
}
int hungary()
{
	int res = 0;
	memset(linker,-1,sizeof(linker));
	for(int u = 0;u < uN;u++)
	{
		memset(used,false,sizeof(used));
		if(dfs(u))res++;
	}
	return res;
}
int a[110][110];
int b[100];
int main()
{
	freopen("in.txt","r",stdin);

	int n,m,k;
	int u,v;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n == 0 && m == 0)break;
		scanf("%d",&k);

		memset(a,0,sizeof(a));
		while(k--)
		{
			scanf("%d%d",&u,&v);
			u--;v--;
			a[u][v] = -1;
		}
		int index = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				 if(a[i][j]!=-1)
				 {
					 b[index] = i*m + j;
					 a[i][j] = index++;
				 }
		uN = vN = index;
		memset(g,0,sizeof(g));
		for(int i = 0;i < n;i++)
			for(int j= 0;j < m;j++)
				if(a[i][j]!=-1 && (i+j)%2==1)
				{
					u = a[i][j];
					if(i > 0 && a[i-1][j]!=-1)
						g[u][a[i-1][j]]=1;
					if(i < n-1 && a[i+1][j]!=-1)
						g[u][a[i+1][j]]=1;
					if(j > 0 && a[i][j-1]!=-1)
						g[u][a[i][j-1]]=1;
					if(j < m-1 && a[i][j+1]!=-1)
						g[u][a[i][j+1]]=1;
				}
		int ans = hungary();
		printf("%d\n",ans);
		for(int i = 0;i <vN;i++)
			if(linker[i]!=-1)
			{
				int x1 = b[i]/m;
				int y1 = b[i]%m;
				int x2 = b[linker[i]]/m;
				int y2 = b[linker[i]]%m;
				printf("(%d,%d)--(%d,%d)\n",x1+1,y1+1,x2+1,y2+1);
			}
		printf("\n");
	}
	return 0;
}