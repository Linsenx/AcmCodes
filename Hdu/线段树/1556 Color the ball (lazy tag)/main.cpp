#include <bits/stdc++.h>
using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N = 150001;
int sum[N<<2], lazy[N<<2];

void build(int l, int r, int rt)
{
  sum[rt] = 0;
  lazy[rt] = 0;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
}

void pushDown(int len, int rt)
{
  if (lazy[rt] != 0) {
    lazy[rt<<1] += lazy[rt];
    lazy[rt<<1|1] += lazy[rt];
    sum[rt<<1] += lazy[rt]*(len-len/2);
    sum[rt<<1|1] += lazy[rt]*(len/2);
    lazy[rt] = 0;
  }
}

void pushUp(int rt)
{
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void update(int L, int R, int l, int r, int rt)
{
  if (L <= l && r <= R) {
    lazy[rt] += 1;
    sum[rt] += r - l + 1;
    return;
  }
  pushDown(r-l+1, rt);
  int m = (l + r) >> 1;
  if (L <= m)
    update(L, R, lson);
  if (R > m)
    update(L, R, rson);
}

int query(int p, int l, int r, int rt)
{
  if (l == r) {
    return sum[rt];
  }
  pushDown(r-l+1, rt);
  int m = (l + r) >> 1;
  int ans = 0;
  if (p <= m)
    ans = query(p, lson);
  if (p > m)
    ans = query(p, rson);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n, a, b;
  while (cin >> n && n != 0) {
    build(1, n, 1);
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      update(a, b, 1, n, 1);
    }

    for (int i = 1; i <= n; ++i) {
      cout << query(i, 1, n, 1);
      if (i != n) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
