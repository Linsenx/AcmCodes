#include <bits/stdc++.h>
using namespace std;

struct node
{
  int x;
  int y;
};

const int N = 50 + 10;
int n, k, min_dis;
int some[N][N], dist[N*N], d[N][N];
node nodes[N];

//连通条件d[i][j] >= min_dis
int dfs(int deep, int an, int sn)
{
  if (an >= k) return 1; //min_dis小了
  else if (an + sn < k) return 0; //min_dis大了
  int u = some[deep][0]; //选择一个轴点
  
  for (int i = 0; i < sn; ++i) {
    int v = some[deep][i];
    if (d[u][v] >= min_dis) continue;
    int tsn = 0;
    for (int j = 0; j < sn; ++j) if(d[v][some[deep][j]] >= min_dis) some[deep+1][tsn++] = some[deep][j];
    if (dfs(deep+1, an+1, tsn)) return 1;
    some[deep][i] = 0;
  }
  return 0;
}

int dis(node a, node b)
{
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx*dx + dy*dy;
}

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (~scanf("%d%d", &n, &k)) {
    for (int i = 1; i <= n; ++i) scanf("%d%d", &nodes[i].x, &nodes[i].y);

    int cnt = 0;
    for (int i = 1; i < n; ++i) 
      for (int j = i+1; j <= n; ++j)
      {
        d[i][j] = d[j][i] = dis(nodes[i], nodes[j]);
        cnt++;
        dist[cnt] = d[i][j];
      }
    sort(dist + 1, dist + 1 + cnt);
    
    int l, r, mid;
    double ans;
    l = 1;
    r = cnt;
    while (l <= r) {
      //将全部元素加入some数组
      for (int i = 0; i < n; ++i) some[0][i] = i+1;
      
      mid = (l + r)/2;
      min_dis = dist[mid];
      
      if(dfs(0, 0, n)) {
        l = mid + 1;
        ans = sqrt(dist[mid]);
      } else {
        r = mid - 1;
      }
    }
    printf("%.2f\n", ans);
  }

  return 0;
}
