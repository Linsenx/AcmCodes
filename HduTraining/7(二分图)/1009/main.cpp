#include <bits/stdc++.h>
using namespace std;

const int N = 300 + 10;
int p, n, G[N][N], match[N], vis[N];

bool dfs(int x)
{
  for (int j = 1; j <= p; ++j) {
    if (G[x][j] == 1 && vis[j] == 0) {
      vis[j] = 1;
      if (match[j] == 0 || dfs(match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

void Hungary()
{
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans ++;
  }
  ans == p ? cout << "YES" << endl : cout << "NO" << endl ;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int test, count, stu;
  cin >> test;
  while (test--) {
    cin >> p >> n;
    memset(G, 0, sizeof G);
    memset(match, 0, sizeof match);
    for (int i = 1; i <= p; ++i) {
      cin >> count;
      while (count--) {
        cin >> stu;
        G[stu][i] = 1;
      }
    }
    Hungary();
  }

  return 0;
}
