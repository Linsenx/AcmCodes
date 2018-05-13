#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 200;
int dis[maxn][maxn];
map<string,int> st;
int N, ID;
string startp, endp;

void floyd()
{
  for (int k = 1; k <= ID; ++k)
    for (int i = 1; i <= ID; ++i)
      for (int j = 1; j <= ID; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> N && N != -1) {
    ID = 0;
    st.clear();
    for (int i = 1; i < maxn; ++i)
      for (int j = 1; j < maxn; ++j)
        dis[i][j] = i == j ? 0 : INF;
    
    cin >> startp >> endp;
    st[startp] = ++ID;
    st[endp] = ++ID;
    
    for (int i = 0; i < N; ++i) {
      int t;
      string s, e;
      cin >> s >> e >> t;
      if (!st[s]) st[s] = ++ID;
      if (!st[e]) st[e] = ++ID;
      if (dis[st[s]][st[e]] == INF) {
        dis[st[s]][st[e]] = dis[st[e]][st[s]] = t;
      } else if (t < dis[st[s]][st[e]]) {
        dis[st[s]][st[e]] = dis[st[e]][st[s]] = t;
      }
    }    
    
    floyd();
    
    if (startp == endp) {
      cout << 0 << endl;
    } else {
      cout << (dis[1][2] == INF ? -1 : dis[1][2]) << endl;
    }
  }

  return 0;
}
