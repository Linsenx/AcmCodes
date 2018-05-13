#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int A, B, C, T, ans, flag;
int G[51][51][51], vis[51][51][51]; // z x y

struct Node
{
  int x, y, z, t;
//  Node(int a=0,int b=0,int c=0,int d=0) :x(a),y(b),z(c),t(d){}
//  friend bool operator < (const Node &a, const Node &b)
//  {
//    return a.t > b.t;
//  }
};

bool check(int x, int y, int z)
{
  return (x >= 0 && x < B) && (y >= 0 && y < C) && (z >= 0 && z < A) && !vis[z][x][y] && G[z][x][y] != 1;
}

int dir[6][3] = 
{
  {1,0,0},{-1,0,0},
  {0,1,0},{0,-1,0},
  {0,0,1},{0,0,-1},
};
void bfs()
{
  queue<Node> q;
  Node u, next;
  
  vis[0][0][0] = 1;
  u.x = u.y = u.z = u.t = 0;
  q.push(u);
  
  while (!q.empty())
  {
    u = q.front(); q.pop();
    if (u.z == A-1 && u.x == B-1 && u.y == C-1)
    {
      if (u.t <= T) 
      {
        printf("%d\n", u.t);
        return;
      }
    }
    
    for (int i = 0; i < 6; ++i)
    {
      next.x = u.x + dir[i][0];
      next.y = u.y + dir[i][1];
      next.z = u.z + dir[i][2];
      if (check(next.x, next.y, next.z))
      {
        next.t = u.t + 1;
        vis[next.z][next.x][next.y] = 1;
        q.push(next);
      }
    }
  }
  printf("-1\n");
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int test;
  scanf("%d", &test);
  while (test--)
  {
    scanf("%d%d%d%d", &A, &B, &C, &T);
    for (int z = 0; z < A; ++z)
    for (int x = 0; x < B; ++x)
    for (int y = 0; y < C; ++y) 
    {
      scanf("%d", &G[z][x][y]);
      vis[z][x][y] = 0;
    }
    bfs();
  }

  return 0;
}