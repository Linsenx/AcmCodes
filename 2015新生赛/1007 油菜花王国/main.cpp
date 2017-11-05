#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000005;
vector<int>fib;
int sprite[1005];
int relation[5005];
int par[5005];
int fam[5005];
int fam_k;
int ans[5005];

void getFib() {
  fib.push_back(1);
  fib.push_back(1);
  for (int i = 2; ; ++i) {
    fib.push_back(fib[i-1] + fib[i-2]);
    if (fib[i] >= INF)
      break;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  getFib();

  int n, m, k, a, b;
  while (cin >> n >> m) {
    //初始化变量
    fam_k = 0;
    //读取精灵数据
    for (int i = 0; i < n; ++i) {
      cin >> k;
      if(binary_search(fib.begin(), fib.end(), k))
        sprite[i+1] = 1;
      else
        sprite[i+1] = 0;
    }
    //读取关系链
    for (int j = 0; j < m; ++j) {
      cin >> a >> b;
      if (par[a] == par[b] && par[a] == 0) {
        par[a] = a;
        fam[a] = ++fam_k;
        ans[fam[par[a]]] += sprite[a];
      }
      if (par[a] == 0 && par[b] != 0) {
        par[a] = par[b];
        ans[fam[par[b]]] += sprite[a];
      }
      if (par[b] == 0 && par[a] != 0) {
        par[b] = par[a];
        ans[fam[par[a]]] += sprite[b];
      }
    }
    for (int i = 1; i <= fam_k; ++i) {
      cout << ans[i] << endl;
    }
  }


  return 0;
}
