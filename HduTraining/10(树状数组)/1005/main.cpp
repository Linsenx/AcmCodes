#include <bits/stdc++.h>
using namespace std;

const int maxn = 32050;
int sum[maxn], cnt[maxn], n = maxn;

int lowbits(int x)
{
  return x & (-x);
}

void add(int x, int num)
{
  for (int i = x; i <= n; i += lowbits(i)) {
    sum[i] += num;
  }
}

int getsum(int x)
{
  int ans = 0;
  for (int i = x; i > 0; i -= lowbits(i)) {
    ans += sum[i];
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int m, x, y;
  while (cin >> m) {
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; ++i) {
      cin >> x >> y;
      x++;y++;
      cnt[getsum(x)]++;
      add(x, 1);
    }
    for (int i = 0; i < m; ++i) {
      cout << cnt[i] << endl;
    }
  }

  return 0;
}
