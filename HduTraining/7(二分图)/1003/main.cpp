#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
vector<pair<int, int> > edge;
int n, m, k, kase, mp[maxn][maxn], vis[maxn], match[maxn];

bool dfs(int x)
{
  for (int j = 1; j <= m; ++j) {
    if (mp[x][j] == 1 && vis[j] == 0) {
      vis[j] = 1;
      if (match[j] == 0 || dfs(match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int Hungary()
{
  memset(match, 0, sizeof match);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans ++;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n >> m >> k) {
    edge.clear();
    memset(mp, 0, sizeof mp);
    int a, b;
    for (int i = 0; i < k; ++i) {
      cin >> a >> b;
      mp[a][b] = 1;
      edge.push_back(make_pair(a, b));
    }
    int max_match = Hungary(), now_match;
    int important_points = 0;
  
    for (int i = 0; i < k; ++i) {
      mp[edge[i].first][edge[i].second] = 0;
      if (Hungary() < max_match) important_points ++;
      mp[edge[i].first][edge[i].second] = 1;
    }
    cout << "Board " << ++kase << " have " << important_points << " important blanks for " << max_match << " chessmen." << endl;
  }

  return 0;
}
