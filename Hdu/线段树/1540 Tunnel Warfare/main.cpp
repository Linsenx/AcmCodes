#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int n, m;
struct node
{
  int l, r;
  int lmax, rmax, mmax; //lmax: 从l->r连续村庄个数 rmax: 从r->l连续村庄个数 mmax: 区间最大村庄个数
} tre[maxn << 2];
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1

void pushUp(int rt)
{
  tre[rt].lmax = tre[rt<<1].lmax;
  tre[rt].rmax = tre[rt<<1|1].rmax;
  tre[rt].mmax = max(tre[rt].lmax, tre[rt].rmax);
  if (tre[rt<<1].lmax == tre[rt<<1].r - tre[rt<<1].l + 1) tre[rt].lmax += tre[rt<<1|1].lmax;
  if (tre[rt<<1|1].rmax == tre[rt<<1|1].r - tre[rt<<1|1].l + 1) tre[rt].rmax += tre[rt<<1].rmax;
  tre[rt].mmax = max(tre[rt].mmax, tre[rt<<1].rmax + tre[rt<<1|1].lmax);
}

void build(int l, int r, int rt)
{
  tre[rt].l = l;
  tre[rt].r = r;
  tre[rt].lmax = tre[rt].rmax = tre[rt].mmax = r - l + 1;
  if (l == r) return;
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  //pushUp(rt);
}

void update(int p, int x, int rt)
{
  if (tre[rt].l == tre[rt].r)
  {
    if (x == 1)
      tre[rt].lmax = tre[rt].rmax = tre[rt].mmax = 1;
    else
      tre[rt].lmax = tre[rt].rmax = tre[rt].mmax = 0;
    return;
  }
  int m = (tre[rt].l+tre[rt].r) >> 1;
  if (p <= m)
    update(p, x, rt<<1);
  else
    update(p, x, rt<<1|1);
  pushUp(rt);
}

int query(int p, int rt)
{
  if (tre[rt].l == tre[rt].r || tre[rt].mmax == 0 || tre[rt].mmax == tre[rt].r - tre[rt].l + 1)
  {
    return tre[rt].mmax;
  }

  int m = (tre[rt].l+tre[rt].r) >> 1;
  if (p <= m)
  {
    if (p >= tre[rt<<1].r - tre[rt<<1].rmax + 1)
      return query(p, rt<<1) + query(m+1, rt<<1|1);
    else
      return query(p, rt<<1);
  }
  else
  {
    if (p <= tre[rt<<1|1].l + tre[rt<<1|1].lmax - 1)
      return query(p, rt<<1|1) + query(m, rt<<1);
    else
      return query(p, rt<<1|1);
  }

}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  /*build(1,4,1);
  update(1,0,1);
  update(2,1,1);
  update(3,1,1);
  update(4,1,1);
  cout << query(1,1) ;*/
  while (cin >> n >> m)
  {
    build(1, n, 1);
    char comm;
    int a, b;
    stack<int>destory;
    while (m--)
    {
      cin >> comm;
      if (comm == 'D')
      {
        cin >> a;
        destory.push(a);
        update(a, 0, 1);
      }
      else if (comm == 'R')
      {
        b = destory.top(); destory.pop();
        update(b, 1, 1);
      }
      else if (comm == 'Q')
      {
        cin >> a;
        cout << query(a, 1) << endl;
      }
    }
  }

  return 0;
}
