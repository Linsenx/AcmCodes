#include <bits/stdc++.h>
using namespace std;

const int INF = 1e7 + 10;
const int N = 205;
int dis[N][N];
int n, m;

void floyd()
{
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = i == j ? 0 : INF;
       
    int a, b, c;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      //可能存在重边
      if (dis[a][b] > c)
        dis[a][b] = dis[b][a] = c;
    }
    
    int s, t;
    cin >> s >> t;
    floyd();
    cout << (dis[s][t] == INF ? -1 : dis[s][t]) << endl;
    
  }

  return 0;
}