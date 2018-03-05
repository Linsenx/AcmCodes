#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int maxn = 15;
int n, m, t;
int vis[2][maxn][maxn];
char mp[2][maxn][maxn];
struct Node
{
  int x, y, cost, lv;
};
Node sp, ep;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check(int x, int y, int lv)
{
  return (x >= 0 && x < n && y >= 0 && y < m && mp[lv][x][y] != '*');
}

void bfs()
{
  memset(vis, 0, sizeof vis);
  queue<Node> Que;
  sp.cost = 0;
  vis[sp.lv][sp.x][sp.y] = 1;
  Que.push(sp);
  Node now, next;

  while (!Que.empty())
  {
    now = Que.front(); Que.pop();

    for (int i = 0; i < 4; ++i)
    {
      next.lv = now.lv;
      next.x = now.x + dx[i];
      next.y = now.y + dy[i];
      if (!vis[next.lv][next.x][next.y] && check(next.x, next.y, next.lv))
      {
        //cout << now.lv << "|" << now.x <<"," << now.y << "=>" << next.x <<"," << next.y << endl;
        vis[next.lv][next.x][next.y] = 1;
        if (mp[next.lv][next.x][next.y] == '#')
        {
          next.lv = !now.lv;
          if (mp[next.lv][next.x][next.y] == '#') continue; //无限传送，永远无法到达
        }
        next.cost = now.cost + 1;
        if (mp[next.lv][next.x][next.y] == '*') continue;
        if (next.lv == ep.lv && next.x == ep.x && next.y == ep.y)
        {
          if (next.cost <= t) cout << "YES\n";
          else cout << "NO\n";
          return;
        }
        Que.push(next);
      }
    }
  }
  cout << "NO\n";
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int test;
  cin >> test;
  while (test --)
  {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      cin >> mp[0][i][j];
      if (mp[0][i][j] == 'S') sp.x = i, sp.y = j, sp.lv = 0;
      if (mp[0][i][j] == 'P') ep.x = i, ep.y = j, ep.lv = 0;
    }
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      cin >> mp[1][i][j];
      if (mp[1][i][j] == 'S') sp.x = i, sp.y = j, sp.lv = 1;
      if (mp[1][i][j] == 'P') ep.x = i, ep.y = j, ep.lv = 1;
    }
    bfs();
  }

  return 0;
}
