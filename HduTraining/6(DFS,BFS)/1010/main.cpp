#include <bits/stdc++.h>
using namespace std;

const int N = 25;
char mp[N][N];
int n, m, t, sx, sy, ex, ey, vis[N][N][1025]; 

struct Node
{
  int x, y, cost, key;
};

bool check(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '*';
}

int dir[4][2] = {1,0,-1,0,0,1,0,-1};
void bfs()
{
  queue<Node> Q;
  Node now, next;
  now.x = sx;
  now.y = sy;
  now.key = 0; //0000000000 从右数第i位(0<=i<=9)为1代表有第('A'~'J')把钥匙
  now.cost = 0;
  Q.push(now);
  
  while(!Q.empty()) 
  {
    now = Q.front(); Q.pop();
    
    for (int i = 0; i < 4; ++i) 
    {
      next.key = now.key;
      next.x = now.x + dir[i][0];
      next.y = now.y + dir[i][1];
      if (check(next.x, next.y) && !vis[next.x][next.y][next.key])
      {
        if (mp[next.x][next.y] >= 'A' && mp[next.x][next.y] <= 'J')
        {
          int kid = mp[next.x][next.y] - 'A';
          if (!(next.key >> kid & 1)) continue;
        }
        if (mp[next.x][next.y] >= 'a' && mp[next.x][next.y] <= 'j')
        {
          int kid = mp[next.x][next.y] - 'a';
          next.key = next.key | (1 << kid);
        }
        next.cost = now.cost + 1;
        vis[next.x][next.y][next.key] = 1;
        if (next.x == ex && next.y == ey)
        {
          cout << (next.cost < t ? next.cost : -1) << endl;
          return;
        }
        Q.push(next);
      }
    }
  
  }
  
  cout << -1 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n >> m >> t) {
    for (int i = 0; i < n; ++i) 
    for (int j = 0; j < m; ++j) {
      cin >> mp[i][j];
      if (mp[i][j] == '@') sx = i, sy = j;
      if (mp[i][j] == '^') ex = i, ey = j;
    }
    memset(vis, 0, sizeof(vis));
    bfs();
  }

  return 0;
}
