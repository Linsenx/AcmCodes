#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000005;
vector<int>fib;
int sprite[1005];
int relation[5005];
int par[5005];
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

  int n, m, k;
  while (cin >> n >> m) {
    //读取精灵数据
    for (int i = 0; i < n; ++i) {
      cin >> k;
      if(binary_search(fib.begin(), fib.end(), k))
        sprite[i] = 1;
      else
        sprite[i] = 0;
    }
    //读取关系链
  }


  return 0;
}
