#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;
int p[MAXN];
int d[MAXN][MAXN];
int power[MAXN][MAXN];
int V;
int dp[10010];

void floyd()
{
  for (int k = 0; k < V; ++k)
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j)
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          power[i][j] = power[i][k] + p[j];
        }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int t, n, m, st, ed, dis, x;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    V = n + 1;
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j) {
        d[i][j] = i == j ? 0 : INF;
        power[i][j] = 0;
      }
    
    while (m--) {
      cin >> st >> ed >> dis;
      if (d[st][ed] > dis)
        d[st][ed] = d[ed][st] = dis;
    }
    
    int power_sum = 0;
    for (int i = 1; i < V; ++i) {
      cin >> x;
      p[i] = x;
      power_sum += x;
    }
    
    floyd();
    
    fill(dp, dp + power_sum, INF);
    dp[0] = 0;
    for (int i = 1; i < V; ++i)
      for (int j = power_sum; j >= p[i]; j--)
        dp[j] = min(dp[j], dp[j-p[i]] + d[0][i]);
        
    /*
      01背包
      dp[j] : 获得j电量所需最小总路程 
      
      for(i: 1->V) 
        for(j: sum->p[j])
          dp[j] = min(dp[j], dp[j-p[i]] + d[0][i])
    
    */
        
    int min_len = INF;
    for (int i = power_sum / 2 + 1; i < power_sum; ++i) {
      min_len = min(min_len, dp[i]);
    }
    min_len == INF ? cout << "impossible" << endl : cout << min_len << endl;
  }

  return 0;
}
