#include <bits/stdc++.h>
using namespace std;

int N, M;
int val[210];
int fa[210];
int dp[210][210];
vector<int>tree[210];

void dfs(int x, int step)
{
  if (step > M) return;

  for (int i = 0; i < tree[x].size(); ++i) {
    int son = tree[x][i];

    for (int j = 0; j < (tree[x].size() - step))
    //dfs(son, step + 1);

  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> N >> M && (N+M)) {
    memset(val, 0, sizeof(val));
    memset(fa, -1, sizeof(fa));

    int a, b;
    for (int i = 1; i <= N; ++i) {
      dp[i][1] = dp[i][0] = 0;
      tree[i].clear();
    }

    for (int ii = 1; ii <= N; ++ii) {
      cin >> a >> b;
      fa[ii] = a;
      val[ii] = b;
      tree[a].push_back(ii);
    }

    dfs(0, 0);

    //cout << dp[0][1];
    //for (int j = 0; j < N; )

  }

  return 0;
}
