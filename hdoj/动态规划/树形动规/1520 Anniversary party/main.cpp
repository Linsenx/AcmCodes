#include <bits/stdc++.h>
using namespace std;

int N, L, K;
int fa[6010];
int happy[6010];
int dp[6010][2];
vector<int>tree[6010];

//dp[i][0] 编号i的人不参加
//dp[i][1] 编号i的人参加
void dfs(int x)
{
  dp[x][1] = happy[x];
  for (int i = 0; i < tree[x].size(); ++i) {
    int son = tree[x][i];
    dfs(son);
    dp[x][0] += max(dp[son][0], dp[son][1]);
    dp[x][1] += dp[son][0];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> N) {
    memset(happy, 0, sizeof(happy));
    memset(fa, -1, sizeof(fa));
    
    for (int i = 1; i <= N; ++i)  {
      cin >> happy[i];
      tree[i].clear();
      dp[i][0] = dp[i][1] = 0;
    }
      
      
    while (cin >> L >> K && L != 0 && K != 0) {
      fa[L] = K;
      tree[K].push_back(L);
    }
    
    //找到树的根t
    int t = 1;
    while (fa[t] != -1) t = fa[t];
    
    dfs(t);
    
    cout << max(dp[t][1], dp[t][0]) << endl;
  }

  return 0;
}