#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(i=a;i<b;++i)

struct Node
{
  int x, y;
};

struct SNode
{
  int bx, by, mx, my, cnt, mmap[10][10];
  friend bool operator < (SNode a, SNode b)
  {
    return a.cnt > b.cnt;
  }
} s;

int m, n, mp[10][10], mx, my, sx, sy, ex, ey, ans;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
 
bool check(int x, int y)
{
  return x >= 0 && x < m && y >= 0 && y < n;
}


bool bfs(int x0, int y0, int x1, int y1, int mmap[10][10])
{
  int visit[10][10], flag[10][10];
  memset(flag, 0, sizeof(flag));
  memset(visit, 0, sizeof(visit));
  
  if (!check(x0, y0)) return false;
  if (!check(x1, y1)) return false;
  
  queue<Node>Q;
  Node now, next;
  now.x = x0; now.y = y0;
  flag[now.x][now.y] = 1;
  visit[now.x][now.y] = 1;
  Q.push(now);
  
  while (!Q.empty())
  {
    now = Q.front(); Q.pop();
    for (int i = 0; i < 4; ++i)
    {
      next.x = now.x + dir[i][0];
      next.y = now.y + dir[i][1];
      if (!visit[next.x][next.y] && check(next.x, next.y) && mmap[next.x][next.y] != 1 && mmap[next.x][next.y] != 2)
      {
        Q.push(next);
        flag[next.x][next.y] = 1;
        visit[next.x][next.y] = 1;
      }
    }
  }
  
  return flag[x1][y1];
}

void show(SNode a, SNode b)
{
  int i, j;
  rep(i,0,m)
  {
    rep(j,0,n)
    {
      cout << a.mmap[i][j];
    }
    cout << "|";
    rep(j,0,n)
    {
      cout << b.mmap[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void bbfs(int bx, int by, int mx, int my, int cnt)
{
  int vis[10][10][4];
  memset(vis, 0, sizeof vis);
  
  queue<SNode> Q;
  SNode now, next;
  now = s;
  now.bx = bx; now.by = by; 
  now.mx = mx; now.my = my; 
  now.cnt = cnt;
  Q.push(now);
  
  while(!Q.empty())
  {
    now = Q.front(); Q.pop();
    
    for (int i = 0; i < 4; ++i)
    {
      next = now;
      int dx = dir[i][0];
      int dy = dir[i][1];
      next.bx += dx;
      next.by += dy;  
      
      if (now.bx == ex && now.by == ey)
      {
        ans = min(ans, next.cnt);
        return;
      }
      
      //人的目标位置
      next.mx = now.bx - dx;
      next.my = now.by - dy;
      if (bfs(now.mx, now.my, next.mx, next.my, next.mmap) && check(next.mx, next.my)) 
      {
        if (check(next.bx, next.by) && next.mmap[next.bx][next.by] != 1 && !vis[next.bx][next.by][i])
        {
          vis[next.bx][next.by][i] = 1;
          next.cnt = now.cnt + 1;          
          swap(next.mmap[next.bx][next.by], next.mmap[now.bx][now.by]);
          swap(next.mmap[next.mx][next.my], next.mmap[now.mx][now.my]);
          Q.push(next);
        }
      }
      

//      if (check(next.bx, next.by) && next.mmap[next.bx][next.by] != 1 && !vis[next.bx][next.by][i])
//      {
//        //人的目标位置
//        next.mx = now.bx - dx;
//        next.my = now.by - dy;
//        if (!check(next.mx, next.my)) continue;
//        if (bfs(now.mx, now.my, next.mx, next.my, next.mmap)) 
//        {
//          vis[next.bx][next.by][i] = 1;
//          next.cnt = now.cnt + 1;          
//          swap(next.mmap[next.bx][next.by], next.mmap[now.bx][now.by]);
//          swap(next.mmap[next.mx][next.my], next.mmap[now.mx][now.my]);
//          Q.push(next);
//        }
//      }
      
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
  
  int test, i, j;
  cin >> test;  
  while (test--)
  {
    cin >> m >> n;
    rep(i,0,m)rep(j,0,n) 
    {
      cin >> mp[i][j];
      s.mmap[i][j] = mp[i][j];
      if (mp[i][j] == 4) {mx = i, my = j;}
      if (mp[i][j] == 2) {sx = i, sy = j;}
      if (mp[i][j] == 3) ex = i, ey = j;
    }
    ans = 1e9;
    bbfs(sx,sy,mx,my,0);
    ans == 1e9 ? cout << -1 << endl : cout << ans << endl;
  }

  return 0;
}
