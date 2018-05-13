#include <bits/stdc++.h>
using namespace std;

const int maxn = 1011;
const int INF = 0xffffff;
int dis[maxn][maxn];
int V, kase;

int ID;
vector<int> cars;
map<string, int>loc;

void floyd()
{
  for (int k = 1; k <= V; ++k)
    for (int i = 1; i <= V; ++i)
      if (dis[i][k] != INF)
        for (int j = 1; j <= V; ++j)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, c, r;
  while (cin >> n >> c >> r) {
    if (n == 0 && c == 0 && r == 0) break;
    V = n;
    ID = 1;
    cars.clear();
    loc.clear();
    for (int i = 1; i <= V; ++i)
      for (int j = 1; j <= V; ++j)
        dis[i][j] = i == j ? 0 : INF;
    
    string location;
    for (int i = 0; i < c + 1; ++i) {
      cin >> location;
      if (loc[location] == 0)
        loc[location] = ID++;
      cars.push_back(loc[location]);
    }
        
    for (int i = 0; i < r; ++i) {
      string st, middle, et;
      cin >> st >> middle >> et;
      
      if (loc[st] == 0) loc[st] = ID++;
      if (loc[et] == 0) loc[et] = ID++;
      
      int cost = 0;
      for (int j = 0; j < middle.length(); ++j) {
        if (middle[j] >= '0' && middle[j] <= '9') {
          if (cost == 0) cost = middle[j] - '0';
          else cost = cost * 10 + middle[j] - '0';
        }
      }
      
      if (middle[0] == '<' && dis[loc[et]][loc[st]] > cost) dis[loc[et]][loc[st]] = cost;
      if (middle[middle.length()-1] == '>' && dis[loc[st]][loc[et]] > cost) dis[loc[st]][loc[et]] = cost;
    }
    
    floyd();
    
    int sum = 0;
    for (int i = 1; i < cars.size(); ++i) {
      int u = cars[i];
      sum = sum + dis[1][u] + dis[u][1];
    }
    cout << ++kase << ". " << sum << endl;
  }

  return 0;
}
