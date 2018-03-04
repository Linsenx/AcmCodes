#include<stdio.h>  
#include<queue>  
#include<map>  
#include<string>  
#include<string.h>  
using namespace std;  
#define inf 0xffffff  
map<string,int>mp;  
int n,c,r,maze[110][110];  
void floyd()  
{  
	 for(int k=1;k<=n;k++)  
			for(int i=1;i<=n;i++)  
				if(maze[i][k]!=inf)  
				 for(int j=1;j<=n;j++)  
						{  
							 if(maze[i][j]>maze[i][k]+maze[k][j])  
									maze[i][j]=maze[i][k]+maze[k][j];  
						}  
}  
	
int main()  
{  
	//freopen("in.txt","r",stdin);
		char a[50],b[50],t[30];  
		char d[1010][110];  
		int k,cas=1;  
		while(scanf("%d%d%d",&n,&r,&c)!=EOF)  
		{  
				k=1;  
				if(n==0&&r==0&&c==0) break;  
				mp.clear();  
				for(int i=0;i<110;i++)  
				for(int j=0;j<110;j++)  
				if(i==j) maze[i][j]=0;  
				else maze[i][j]=inf;  
				for(int i=0;i<=r;i++)  
				{  
						scanf("%s",&d[i]);  
						if(mp[d[i]]==0)  
								mp[d[i]]=k++;  
				}  
				for(int ii=0;ii<c;ii++)  
				{  
						scanf("%s%s%s",&a,&t,&b);  
						if(mp[a]==0) mp[a]=k++;  
						if(mp[b]==0) mp[b]=k++;  
						int len=strlen(t);  
						int value=0;  
						for(int i=0;i<len;i++)  
						{  
							if (t[i] >= '0' && t[i] <= '9'){
								if (value == 0) value = t[i] - '0';
								else value = value * 10 + t[i] - '0'; 
							}
						}  
						//printf("val:%d\n", value);
						//printf("\nvalue=%d\n",value);  
						int u=mp[a],v=mp[b];  
						//printf("a=%d b=%d\n",u,v);  
						if(t[0]=='<'&&maze[v][u]>value) maze[v][u]=value;  
						if(t[len-1]=='>'&&maze[u][v]>value) maze[u][v]=value;  
				}  
				floyd();  
					
				int sum=0;  
				for(int i=1;i<=r;i++)  
				{  
					 sum+=maze[mp[d[0]]][mp[d[i]]]+maze[mp[d[i]]][mp[d[0]]];  
				}  
				printf("%d. %d\n",cas++,sum);  
				}  
	
}  
