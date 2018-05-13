#include <bits/stdc++.h>
using namespace std;

const int INF = 0xffff;
const int N = 1100;
int dis[N][N];
int t, s, d, V;
int city;
vector<int> neighbor;
vector<int> destination;

void floyd()
{
  for (int k = 1; k <= V; ++k) 
    for (int i = 1; i <= V; ++i)
      if (dis[i][k] != INF) {
        for (int j = 1; j <= V; ++j)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> t >> s >> d) {
    int a, b, c;
    neighbor.clear();
    destination.clear();
    
    for (int i = 1; i <= N-1; ++i)
      for (int j = 1; j <= N-1; ++j)
        dis[i][j] = i == j ? 0 : INF;
    
    for (int i = 0; i < t; ++i) {
      cin >> a >> b >> c;
      if (dis[a][b] == INF) {
        dis[a][b] = dis[b][a] = c;
      } else if (dis[a][b] > c) {
        dis[a][b] = dis[b][a] = c;
      }
      city = max(city, max(a, b));
    }
    V = city;
    floyd();
    
    int x;
    for (int i = 0; i < s; ++i) {
      cin >> x;
      neighbor.push_back(x);
    }
    for (int i = 0; i < d; ++i) {
      cin >> x;
      destination.push_back(x);
    }
    int min_len = INF;
    for (int i = 0; i < s; ++i) 
      for (int j = 0; j < d; ++j)
        min_len = min(min_len, dis[neighbor[i]][destination[j]]);
        
    cout << min_len << endl;
  }

  return 0;
}
