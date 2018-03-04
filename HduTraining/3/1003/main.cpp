#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int INF = 9999999;

int n;
int tax[N];
int dis[N][N];
int path[N][N];

void floyd()
{
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        int tmp_len = dis[i][k] + dis[k][j] + tax[k];
        if (dis[i][j] > tmp_len) {
          dis[i][j] = tmp_len;
          path[i][j] = path[i][k];
        } else if (dis[i][j] == tmp_len) {
          if (path[i][j] > path[i][k]) {
            path[i][j] = path[i][k];
          }
        }
      }
}

void outpath(int s, int t)
{
  /*
    From 1 to 3 :
    Path: 1-->5-->4-->3
    Total cost : 21
  */
  printf("From %d to %d :\n", s, t);
  printf("Path: %d", s);
  int v = s;
  while (v != t) {
    printf("-->%d", path[v][t]);
    v = path[v][t];
  }
  printf("\nTotal cost : %d\n\n", dis[s][t]);
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n && n) {
    int x;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        cin >> x;
        dis[i][j] = x == -1 ? INF : x;
        path[i][j] = j;
      }
    
    for (int i = 1; i <= n; ++i) {
      cin >> x;
      tax[i] = x;
    }
    
    floyd();
    
    int a, b;
    while (cin >> a >> b && (a != -1 && b != -1)) {
      outpath(a, b);
    }
    
  }
  

  return 0;
}
