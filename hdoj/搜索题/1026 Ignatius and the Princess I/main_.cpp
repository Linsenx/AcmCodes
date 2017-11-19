#include <bits/stdc++.h>
using namespace std;

int ttt = 0;
int N, M, min_dis;
const int INF = 100000000;
char maps[105][105];
int dis[105][105];
int dirs[105][105];
int fight[105][105];
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};

struct pp
{
	int x;
	int y;
	friend bool operator <(pp a,pp b)  
	{  
		return dis[a.x][a.y] > dis[b.x][b.y];  
	}
};

//struct node
//{
//	pp last;
//	pp next;
//	int fight;
//};
//node nodes[110][110];

int bfs()
{
	pp s, tmp;
	int nx, ny;
	priority_queue<pp> q;
	s.x = 0; s.y = 0;
	q.push(s);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			dirs[i][j] = -1;
			dis[i][j] = 0;
			fight[i][j] = 0;
		}
	}
	if (maps[0][0] >= '1' && maps[0][0] <= '9') {
		int fightt = (int)(maps[0][0] - '0');
		fight[0][0] = fightt;
		dis[0][0] = fightt;
	}

	
	while (!q.empty())
	{
		tmp = q.top();
		q.pop();
		if (tmp.x == N-1 && tmp.y == M-1) 
		{
			return dis[tmp.x][tmp.y];
		}
		
		for (int i = 0; i < 4; i++)
		{
			s = tmp;
			s.x += dir[i][0];
			s.y += dir[i][1];
			if (s.x < 0 || s.y < 0 || s.x >= N || s.y >= M || maps[s.x][s.y] == 'X') continue;
			
			if (maps[s.x][s.y] != '.') {
				dis[s.x][s.y] = maps[s.x][s.y] - '0';
				fight[s.x][s.y] = maps[s.x][s.y] - '0';
			}
			
			dirs[s.x][s.y] = i;
			
			dis[s.x][s.y] = dis[s.x][s.y] + dis[tmp.x][tmp.y] + 1;
			maps[s.x][s.y] = 'X';
			q.push(s);
		}
		
		
	}
	return -1;
}

void printfpath(int x, int y) 
{
	if (x == 0 && y == 0) {
		if (fight[0][0] > 0) {
			for (int i = 0; i < fight[0][0]; ++i) {
				printf("%ds:FIGHT AT (%d,%d)\n", ++ttt, x, y);
			}
		}
		return;
	}
	int nx = x - dir[dirs[x][y]][0];
	int ny = y - dir[dirs[x][y]][1];
	printfpath(nx, ny);
	printf("%ds:(%d,%d)->(%d,%d)\n", ++ttt, nx, ny, x, y);
	if (fight[x][y] > 0) {
		for (int i = 0; i < fight[x][y]; ++i) {
			printf("%ds:FIGHT AT (%d,%d)\n", ++ttt, x, y);
		}
	}
}

int main()
{
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif

	while (scanf("%d%d", &N, &M) != EOF) {

	for (int i = 0; i < N; ++i)
		scanf("%s", maps[i]);
			
		min_dis = bfs();
		if (min_dis != -1) 
		{
			ttt = 0;
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", min_dis);
			printfpath(N-1, M-1);
			printf("FINISH\n");
		}
		else 
		{
			printf("God please help our poor hero.\nFINISH\n");
		}
	}


	return 0;
}
