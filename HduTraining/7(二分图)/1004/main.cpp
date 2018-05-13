#include <bits/stdc++.h>
using namespace std;

const int maxn = 1100 + 10;
set<int> colors;
int n, k, mp[maxn][maxn], vis[maxn], match[maxn];

bool dfs(int color, int x)
{
  for (int j = 1; j <= n; ++j) {
    if (mp[x][j] == color && !vis[j]) {
      vis[j] = 1;
      if (match[j] == 0 || dfs(color, match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int Hungary(int color)
{
  memset(match, 0, sizeof match);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(color, i)) ans ++;
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
  
  int x;
  while (cin >> n >> k) {
    if (!n && !k) break;
    memset(mp, 0, sizeof mp);
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      cin >> x;
      colors.insert(x);
      mp[i][j] = x;
    }
    vector<int> impossible;
    for (auto color : colors) {
      if (Hungary(color) > k) impossible.push_back(color);
    }
    if (impossible.size() == 0) cout << -1 << endl;
    else {
      sort(impossible.begin(), impossible.end());
      cout << impossible[0];
      for (int i = 1; i < impossible.size(); ++i) {
        cout << " " << impossible[i];
      }
      cout << endl;
    }
  }

  return 0;
}