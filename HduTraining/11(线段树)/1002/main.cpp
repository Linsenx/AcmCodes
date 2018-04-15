#include <iostream>
using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define Mid int m = (l+r)>>1
const int maxn = 2e5;
int sum[maxn<<2];

void pushUp(int rt)
{
  sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}

void build(int l, int r, int rt)
{
  sum[rt] = 0;
  if (l == r) {
    cin >> sum[rt];
    return;
  }
  Mid;
  build(lson);
  build(rson);
  pushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
  if (L <= l && r <= R) {
    return sum[rt];
  }
  Mid;
  //L R M
  if (R <= m)
    return query(L, R, lson);
  if (m < L)
    return query(L, R, rson);
  return max(query(L, R, lson), query(L, R, rson));
}

void update(int p, int change, int l , int r, int rt)
{
  if (l == r) {
    sum[rt] = change;
    return;
  }
  Mid;
  if (p <= m)
    update(p, change, lson);
  if (p > m)
    update(p, change, rson);
  pushUp(rt);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n, m, x, y;
  char cmd;
  while (cin >> n >> m) {
    build(1, n, 1);
    while (m--) {
      cin >> cmd >> x >> y;
      if (cmd == 'Q') {
        cout << query(x, y, 1, n, 1) << endl;
      } else {
        update(x, y, 1, n, 1);
      }
    }
  }

  return 0;
}
