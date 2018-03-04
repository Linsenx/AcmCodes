#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
int n, m, sum[maxn<<2];

void pushUp(int rt)
{
  sum[rt] = max(sum[rt<<1], sum[rt<<1|1]);
}

void build(int l, int r, int rt)
{
  if (l == r)
  {
    cin >> sum[rt];
    return;
  }
  
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  pushUp(rt);
}

void update(int p, int add, int l, int r, int rt)
{
  if (l == r) 
  {
    sum[rt] = max(sum[rt], add);
    return;
  }
  int m = (l+r) >> 1;
  if (p <= m)
    update(p, add, lson);
  else 
    update(p, add, rson);
  pushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
  if (L <= l && r <= R)
  {
    return sum[rt];
  }
  int m = (l+r) >> 1;
  if (R <= m)
    return query(L, R, lson);
  if (m < L)
    return query(L, R, rson);
  return max(query(L, R, lson), query(L, R, rson));
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen(  "in.txt","r",stdin);
  #endif
  
  char Q;
  int a, b;
  while (cin >> n >> m)
  {
    build(1, n, 1);
    while (m--)
    {
      cin >> Q >> a >> b;
      if (Q == 'Q')
      {
        cout << query(a, b, 1, n, 1) << endl;
      }
      else
      {
        update(a, b, 1, n, 1);
      }
    }
  }

  return 0;
}
