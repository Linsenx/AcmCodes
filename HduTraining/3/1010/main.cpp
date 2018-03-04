#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
const int INF = 1e8;
const int RLEN = 2520; // road length
int dis[maxn][maxn];
int V, VN, VM, N, M;

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
  
  while (cin >> N >> M && !(N == 0 && M == 0)) {
    VN = N + 1;
    VM = M + 1;
    V = VN * VM;
    for (int i = 1; i <= V; ++i)
      for (int j = 1; j <= V; ++j)
        dis[i][j] = i == j ? 0 : INF;
    
    int sl, nt; // speed limit, need time
    char dir; // direction 
    for (int i = 0; i < VN + N; ++i) {
      if (i % 2 == 0) {
        //横
        for (int j = 1; j <= M; ++j) {
          cin >> sl >> dir;
          nt = sl == 0 ? INF : RLEN / sl;
          if (dir == '>' || dir == '*') dis[VM*(i/2)+j][VM*(i/2)+j+1] = nt;
          if (dir == '<' || dir == '*') dis[VM*(i/2)+j+1][VM*(i/2)+j] = nt;
        }
      } else {
        //竖
        for (int j = 1; j <= VM; ++j) {
          cin >> sl >> dir;
          nt = sl == 0 ? INF : RLEN / sl;
          if (dir == 'v' || dir == '*') dis[VM*((i-1)/2)+j][VM*((i-1)/2)+j+VM] = nt;
          if (dir == '^' || dir == '*') dis[VM*((i-1)/2)+j+VM][VM*((i-1)/2)+j] = nt;
        }
      }
    }
    
    floyd();
    
    dis[1][V] == INF ? cout << "Holiday" << endl : cout << dis[1][V] << " blips" << endl;
  }

  return 0;
}
