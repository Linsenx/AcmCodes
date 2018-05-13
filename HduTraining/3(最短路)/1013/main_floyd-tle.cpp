#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
int dis[1001][1001];
int cost[1001][1001];
int V;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int s, t;
  int n, m, a, b, d, p;
  while (cin >> n >> m && n + m) {
    V = n;
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j) {
        cost[i][j] = 0;
        dis[i][j] = i == j ? 0 : inf;
      }
    
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> d >> p;
      dis[a-1][b-1] = dis[b-1][a-1] = d;
      cost[a-1][b-1] = cost[b-1][a-1] = p;
    }
    cin >> s >> t;
    for (int k = 0; k < V; ++k)
      for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
          if (dis[i][j] > dis[i][k] + dis[k][j]) {
            dis[i][j] = dis[i][k] + dis[k][j];
            cost[i][j] = cost[i][k] + cost[k][j];
          }
          
//          for (int i = 0; i < V; ++i) {
//            for (int j = 0; j < V; ++j) {
//              printf("%10d", dis[i][j]);
//            }
//            printf("\n");
//          }
    cout << dis[s-1][t-1] << " " << cost[s-1][t-1] << endl;
  }

  return 0;
}
