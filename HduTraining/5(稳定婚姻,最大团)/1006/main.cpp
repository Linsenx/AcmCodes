#include <bits/stdc++.h>
using namespace std;

const int N = 26 + 10;
int n, S;
int G[N][N], color[N], flag, sumcolor;

void dfs(int x)
{
  if (x == n+1 && !flag)
  {
    flag = 1;
    
    for (int i = 1; i <= n; ++i) 
      sumcolor = max(sumcolor, color[i]);
      
    cout << sumcolor << " channel" << (sumcolor > 1 ? "s" : "") << " needed." << endl;
    return;
  }
  
  int i, j;
  for (i = 1; i <= 4; ++i) {
    for (j = 1; j <= n; ++j) {
      if (G[x][j] && color[j] == i)
        break;
    }
    if (j == n+1) {
      color[x] = i;
      dfs(x+1);
      if (flag == 1) return;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n && n) {
    getchar();
    
    flag = 0;
    memset(G, 0, sizeof(G));
    memset(color, 0, sizeof(color));
    
    int a, b;
    string str;
    for (int i = 0; i < n; ++i) {
      cin >> str;
      a = str[0] - 'A' + 1;
      int len = str.length();
      for (int j = 2; j < len; ++j) {
        b = str[j] - 'A' + 1;
        G[a][b] = 1;
      }
    }
    
    sumcolor = 1;
    dfs(1);
  }

  return 0;
}
