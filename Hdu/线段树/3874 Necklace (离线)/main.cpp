#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int N = 5e4 + 100;
int n, m;
int num[N], pre[1000100];
ll sum[N<<2], anss[N<<2];
struct qy {
  int idx, l, r;
} Q[N<<2];

int cmp(qy a, qy b)
{
  return a.r < b.r;
}

void pushUp(int rt)
{
  sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt)
{
  sum[rt] = 0;
  if (l == r) return;
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
}

void update(int p, int val, int l, int r, int rt)
{
  if (l == r) {
    sum[rt] = val;
    return;
  }
  int m = (l + r) >> 1;
  if (p <= m)
    update(p, val, lson);
  else
    update(p, val, rson);
  pushUp(rt);
}

ll query(int L, int R, int l, int r, int rt)
{
  if (L <= l && r <= R) {
    return sum[rt];
  }
  int m = (l + r) >> 1;
  ll ans = 0;
  if (m >= L)
    ans += query(L, R, lson);
  if (m < R)
    ans += query(L, R, rson);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int test, a, b;
  cin >> test;
  while (test--) {
    memset(pre, -1, sizeof pre);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> num[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      Q[i].idx = i;
      Q[i].l = a;
      Q[i].r = b;
    }
    sort(Q, Q+m, cmp);

    build(1, n, 1);
    int st = 1;
    for (int i = 0; i < m; ++i) {
      while (st <= Q[i].r) {
        if (pre[num[st]] == -1) {
          pre[num[st]] = st;
          update(st, num[st], 1, n, 1);
        } else {
          update(pre[num[st]], 0, 1, n, 1);
          update(st, num[st], 1, n, 1);
          pre[num[st]] = st;
        }
        st ++;
      }
      anss[Q[i].idx] = query(Q[i].l, Q[i].r, 1, n, 1);
    }

    for (int i = 0; i < m; ++i) {
      cout << anss[i] << endl;
    }
  }

  return 0;
}
