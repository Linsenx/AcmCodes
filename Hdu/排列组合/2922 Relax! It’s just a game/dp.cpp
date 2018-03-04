//从discuss摘录
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 15
int dp[N][N];
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)&&(a!=-1||b!=-1))
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0; i<=a; i++)
		{
			for(int j=0; j<=b; j++)
			{
				if(i==0&&j==0)
					continue;
				if(i==0)
					dp[i][j]=dp[i][j-1];
				else if(j==0)
					dp[i][j]=dp[i-1][j];
				else
					dp[i][j]=dp[i][j-1]+dp[i-1][j];
			}
		}
		printf("%d+%d",a,b);
		printf("yo:%d\n", dp[a][b]);
		if(dp[a][b]==a+b)
			printf("=");
		else
			printf("!=");
		printf("%d\n",a+b);
	}
	return 0;
}