#include <bits/stdc++.h>
using namespace std;

int x, cnt;

void dfs(int last, int sum, int step) {
  if (sum > x) return;
  if (sum == x) {
    cnt ++;
    return;
  }
  for (int i = 1; i <= last ; ++i) {
    dfs(i, sum+i, step+1);
  }
}


int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> x) {
    cnt = 0;
    dfs(x , 0, 0);
    cout << cnt << endl;
  }

  return 0;
}
