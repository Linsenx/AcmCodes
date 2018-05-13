#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, ans;
int vis[50][50];
char G[50][50];

struct Node 
{
  int x, y, t;
  Node(int a, int b, int c)
  {
    x = a, y = b, t = c;
  }
  friend bool operator < (Node a, Node b)
  {
    return a.t > b.t;
  }
};

bool check(int x, int y)
{
  if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
    return G[x][y] != '*';
  } else return false;
}

int dd[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs()
{
  priority_queue<Node> q;
  
  q.push(Node(sx, sy, 0));
  while (!q.empty())
  {
    Node now = q.top(); q.pop();
    Node next(0, 0, 0);

    if (now.x == ex && now.y == ey) 
    {
      //cout << now.t << endl;
      ans = min(ans, now.t);
      continue;
    }
    
    for (int i = 0; i < 4; ++ i) 
    {
      next.x = now.x + dd[i][0];
      next.y = now.y + dd[i][1];
      next.t = now.t + 1;
      if (check(next.x, next.y)) 
      {
        if (G[next.x][next.y] == '|') 
        {
          next.x += dd[i][0];
          next.y += dd[i][1];
          if (i == 0 || i == 1) 
          {
            if (next.t % 2 == 0) next.t ++;
          }
          else
          {
            if (next.t % 2 == 1) next.t ++;
          }          
        }
        else if (G[next.x][next.y] == '-') 
        {
          next.x += dd[i][0];
          next.y += dd[i][1];
          if (i == 0 || i == 1) 
          {
            if (next.t % 2 == 1) next.t ++;
          }
          else
          {
            if (next.t % 2 == 0) next.t ++;
          }    
        }
        
        if (check(next.x, next.y)) {
          vis[next.x][next.y] = 1;
          q.push(next);
        }
      }
    }
    
    
  }
  
  
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n >> m) {
    memset(vis, 0, sizeof(vis));
    
    char x;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) 
    {
      cin >> x;
      if (x == 'S') sx = i, sy = j;
      else if (x == 'T') ex = i, ey = j;
      G[i][j] = x;
    }
    
    vis[sx][sy] = 1;
    ans = 1e9;
    bfs();
    cout << ans << endl;
  }

  return 0;
}
