#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int x, y, t, ct;
  Node(int a = 0, int b = 0, int c = 0, int d = 0) 
  {
    x = a, y = b, t = c, ct = d;
  }
  friend bool operator < (struct Node a, struct Node b)
  {
    if (a.t == b.t) return a.ct > b.ct;
    else return a.t > b.t;
  }
};

const int N = 200 + 50;
int n, m, ans;
char mp[N][N];
int vis[N][N];
Node startPoint;
vector<Node> endpoints;

bool check(int x, int y)
{
  return (x >= 0 && x < n && y >=0 && y < m && !vis[x][y] && mp[x][y] != '#');
}

int get_time(int x, int y)
{
  if (mp[x][y] == 'x') return 2;
  else return 1;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void bfs()
{
  priority_queue<Node> q;
  
  vis[startPoint.x][startPoint.y] = 1;
  q.push(Node(startPoint.x, startPoint.y, 0, 1));
  
  //cout << startPoint.x <<"-"<<startPoint.y <<endl;
  while (!q.empty())
  {
    Node Next;
    Node u = q.top(); q.pop();
    
    for (auto ep : endpoints)
    {
      if (u.x == ep.x && u.y == ep.y)
      {
        ans = min(ans, u.t);
      }
    }
    
    for (int i = 0; i < 4; ++i)
    {
      Next.x = u.x + dx[i];
      Next.y = u.y + dy[i];
      if (check(Next.x, Next.y))
      {
        int t0, t1;
        Next.t = u.t + u.ct;
        Next.ct = get_time(Next.x, Next.y);
        vis[Next.x][Next.y] = 1;
        q.push(Next);
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
  
  while (~scanf("%d%d", &n, &m)) 
  {
    getchar();
    ans = 1e9;
    endpoints.clear();
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j) 
      {
        scanf("%c", &mp[i][j]);
        if (mp[i][j] == 'a') startPoint.x = i, startPoint.y = j;
        else if (mp[i][j] == 'r') endpoints.push_back(Node(i,j,0,0));
      }
      getchar();
    }

    bfs();  
    
    ans == 1e9 ? printf("Poor ANGEL has to stay in the prison all his life.\n") : printf("%d\n", ans);
  }

  return 0;
}
