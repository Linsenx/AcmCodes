#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1

const int maxn = 1100;
struct node
{
  int type;
  double l, r, h;
  node(){}
  node(double a,double b,double c,int d): l(a),r(b),h(c),type(d){}
  friend bool operator<(node p,node q){       //因为是从下到上扫描因此，需要按照高度排序
    return p.h<q.h;
  }
} lines[maxn];

int tot, lcnt;
int cnt[maxn<<2], kas;
double ls[maxn<<2], sum[maxn<<2];

void pushUp(int l, int r, int rt)
{
  if (cnt[rt] > 0) {
    sum[rt] = ls[r+1]-ls[l];
  }
  else if (l == r)
    sum[rt] = 0;
  else
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l, int r, int rt)
{
   if (l == r) {
     cnt[rt] = 0;
     sum[rt] = 0;
     return;
   }
   int m = (l + r) >> 1;
   //cout << l <<',' << r<<"->" << l <<',' <<m <<"\n";
   build(lson);
   build(rson);
}

void update(int L, int R, int val, int l, int r, int rt)
{
  if (L <= l && r <= R) {
    cnt[rt] += val;
    pushUp(l, r, rt);
    return;
  }
  int m = (l + r) >> 1;
  /*两种写法
  if (L <= m)
    update(L, R, val, l, m, rt<<1);
  if (R > m)
    update(L, R, val, m+1, r, rt<<1|1);*/
  if (R <= m) update(L, R, val, lson);
  else if (L > m) update(L, R, val, rson);
  else {
    update(L, m, val, lson);
    update(m+1, R, val, rson);
  }
  pushUp(l, r, rt);
}

int main()
{
  #ifdef LOCAL_DEBUG
    freopen("in.txt","r",stdin);
  #endif

  int n;
  double x1, y1, x2, y2;
  while (~scanf("%d", &n) && n != 0) {
    tot = 0;
    lcnt = 0;
    memset(cnt, 0, sizeof cnt);
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      ls[tot++] = x1;
      ls[tot++] = x2;
      lines[lcnt++] = node(x1,x2,y1,1);
      lines[lcnt++] = node(x1,x2,y2,-1);
    }
    sort(ls, ls+tot);
    sort(lines, lines+lcnt);
    tot = unique(ls, ls+tot) - ls;
    build(0,tot-1,1);

    double S = 0;
    for (int i = 0; i < lcnt-1; ++i) {
      int ll = lower_bound(ls,ls+tot,lines[i].l) - ls ;
      int rr = lower_bound(ls,ls+tot,lines[i].r) - ls - 1;
      //cout << lines[i].h << "  " << lines[i].type << endl;
      update(ll, rr, lines[i].type, 0, tot-1, 1);
      S += sum[1] * (lines[i+1].h - lines[i].h);
    }

    printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kas, S);
  }

  return 0;
}
