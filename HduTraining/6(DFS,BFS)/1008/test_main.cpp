#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int MAXN = 100 + 10;
int m, n;
int k, sx, sy, ex, ey;
int vis[MAXN][MAXN][4];
char G[MAXN][MAXN];

struct Node
{
	int x, y, cost, dir;
	friend bool operator < (Node a, Node b)
	{
		return a.cost > b.cost;
	}
};

bool check(Node &a)
{
	return (a.x >= 0 && a.x < m && a.y >= 0 && a.y < n && G[a.x][a.y] == '.');
}


int dd[4][2]= {-1,0, 1,0, 0,-1, 0,1}; 
void bfs()
{
	priority_queue<Node> Que;
	Node now, next;
	now.x = sx;
	now.y = sy;
	now.cost = 0;
	now.dir = 1;
	vis[sx][sy][0] = 1;
	vis[sx][sy][1] = 1;
	vis[sx][sy][2] = 1;
	vis[sx][sy][3] = 1;
	Que.push(now);
	
	while (!Que.empty())
	{
		now = Que.top(); Que.pop();
		
		//printf("%d,%d(%d) -> %d\n", now.x, now.y, now.cost, now.dir);

		if (now.x == ex && now.y == ey && now.cost <= k) 
		{
			printf("yes\n");
			return;
		}
		
		for (int i = 0; i < 4; ++i)
		{
			next.x = now.x + dd[i][0];
			next.y = now.y + dd[i][1];
			if (!vis[next.x][next.y][i] && check(next))
			{
				next.dir = i;
				next.cost = now.cost;
				//vis[now.x][now.y][now.dir] = 1; //此处若为 vis[next.x][next.y][next.dir] = 1 则WA
				vis[next.x][next.y][next.dir] = 1;
				if (!(now.x == sx && now.y == sy) && i != now.dir)
				{
					next.cost = now.cost + 1;
				}
				Que.push(next);
			}
		}
	}
	printf("no\n");
}

int main()
{
	//ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif

	int test;
	scanf("%d",&test);  
	while (test--)
	{
		scanf("%d%d",&m,&n);  
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; ++i)
		{
			scanf("%s", G[i]);
		}
		
		scanf("%d%d%d%d%d", &k, &sy, &sx, &ey, &ex);
		sx--;
		sy--;
		ex--;
		ey--;
		bfs();
	}

	return 0;
}