#include <bits/stdc++.h>
using namespace std;

double d[50][50];
int V, m, id, kase;
map<string, int> mp;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> V && V) {
    //初始化dis
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (i == j) d[i][j] = 1;
        else d[i][j] = 0;
      }
    }
    id = 0;
    mp.clear();
    double rate;
    string str0, str1;
    for (int i = 0; i < V; ++i) {
      cin >> str0;
      mp[str0] = id++;
    } 
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> str0 >> rate >> str1;
      d[mp[str0]][mp[str1]] = rate;
    }
    
    //floyd
    for (int k = 0; k < V; ++k)
      for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
          d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
    
    bool isok = false;
    for (int i = 0; i < V; ++i)
      if (d[i][i] > 1) {
        isok = true;
        break;
      }
    cout << "Case " << ++kase << ": ";
    isok ? cout << "Yes" : cout << "No" ;
    cout << endl;
//    for (int i = 0; i < V; ++i) {
//      for (int j = 0; j < V; ++j) {
//        printf("%10.2lf", d[i][j]);
//      }
//      printf("\n");
//    }
  }


  return 0;
}
