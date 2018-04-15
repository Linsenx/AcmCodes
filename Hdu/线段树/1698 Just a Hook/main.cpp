#include <bits/stdc++.h>
using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 1e5;
int n, kas;
int sum[maxn << 2], lazy[maxn << 2];

void pushDown(int rt, int len)
{
  if (lazy[rt] != -1) {
    lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
    sum[rt<<1] = lazy[rt<<1] * (len - (len>>1));
    sum[rt<<1|1] = lazy[rt<<1|1] * (len>>1);
    lazy[rt] = -1;
  }
}

void pushUp(int rt)
{
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt)
{
  sum[rt] = 1;
  lazy[rt] = -1;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
}

void update(int L, int R, int val, int l, int r, int rt)
{
  if (L <= l && r <= R) {
    lazy[rt] = val;
    sum[rt] = val * (r-l+1);
    return;
  }
  pushDown(rt, r-l+1);
  int m = (l + r) >> 1;
  if (L <= m)
    update(L, R, val, lson);
  if (R > m)
    update(L, R, val, rson);
  pushUp(rt);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int test, q, a, b, c;
  cin >> test;
  while (test--) {
    cin >> n;
    cin >> q;
    build(1, n, 1);
    while (q--) {
      cin >> a >> b >> c;
      update(a, b, c, 1, n, 1);
    }
    cout << "Case " << ++kas << ": The total value of the hook is " << sum[1] << ".\n";
  }

  return 0;
}
