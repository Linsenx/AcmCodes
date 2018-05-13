#include <bits/stdc++.h>
using namespace std;

const int INF = 99999;
const int maxn = 100 + 10;

int d[maxn][maxn];
int V;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, m, a, b;
  while (cin >> n >> m) {
    V = n;
    for (int i = 0; i < V; ++i)
      for (int j = 0; j < V; ++j)
        i == j ? d[i][j] = 0 : d[i][j] = INF;
      
    while (m--) {
      cin >> a >> b;
      d[a][b] = 1;
      d[b][a] = 1;
    }
    
    for (int k = 0; k < V; ++k)
      for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      
    bool isok = true;
    for (int i = 0; isok && i < V; ++i)
      for (int j = 0; isok && j < V; ++j) {
//        printf("i:%d j:%d ", i,j);
//        cout << d[i][j] << endl;
        if (d[i][j] > 7 || d[i][j] == INF) {
          isok = false;
        }
      }
    isok ? cout << "Yes" << endl : cout << "No" << endl;
  }

  return 0;
}
