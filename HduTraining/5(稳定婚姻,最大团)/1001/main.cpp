#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
//int S;
int n, max_clique;
int g[MAXN][MAXN];
int all[MAXN][MAXN], some[MAXN][MAXN], none[MAXN][MAXN];

void dfs(int d, int an, int sn, int nn)
{
  //if (S > 1000) return;
  // if P and X are both empty: report R as a maximal clique
  if (sn == 0 && nn == 0) 
  {
    max_clique = max(max_clique, an);
    return;
  }
  
  // choose a pivot vertex u in P ⋃ X
  int u = some[d][1];
  
  // for each vertex v in P \ N(u):
  for (int i = 0; i < sn; ++i) 
  {
    int v = some[d][i];
    if (g[u][v] == 1) continue;  
    
    int tsn = 0, tnn = 0;
    // R ⋃ {v}
    for (int j = 1; j <= an; ++j) all[d+1][j] = all[d][j];
    all[d+1][an] = v;
    // P ⋂ N(v)
    for (int j = 1; j <= sn; ++j) if (g[v][some[d][j]]) some[d+1][++tsn] = some[d][j];
    // X ⋂ N(v)
    for (int j = 1; j <= nn; ++j) if (g[v][none[d][j]]) none[d+1][++tnn] = none[d][j];
    
    dfs(d+1, an+1, tsn, tnn);
    //P := P \ {v}  X := X ⋃ {v}
    some[d][i] = 0; none[d][++nn] = v; 
  }
}

void process()
{
  for (int i = 1; i <= n; ++i) some[1][i] = i; 
  
  max_clique = 0;
  dfs(1, 0, n, 0);
  printf("%d\n", max_clique);
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (~scanf("%d", &n) && n != 0) 
  {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        scanf("%d", &g[i][j]);
    
    process();
  }

  return 0;
}
