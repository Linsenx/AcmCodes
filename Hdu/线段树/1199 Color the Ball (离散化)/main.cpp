#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000;
int n;
int x[maxn << 2], tot, col[maxn << 2];
struct Node
{
  int l, r, col;
} tre[maxn << 2];
struct Node_
{
  int x, y, col;
} node[maxn << 2];

void pushDown(int rt)
{
  if (tre[rt].col != -1) {
    tre[rt<<1].col = tre[rt<<1|1].col = tre[rt].col;
    tre[rt].col = -1;
  }
}

void build(int l, int r, int rt)
{
  tre[rt].l = l;
  tre[rt].r = r;
  tre[rt].col = -1;
  if (l >= r) return;
  int m = (tre[rt].l+tre[rt].r) >> 1;
  build(l, m, rt << 1);
  build(m+1, r, rt << 1 | 1);
}


void update(int col, int l, int r, int rt)
{
  if (tre[rt].l == l && tre[rt].r == r) {
    tre[rt].col = col;
    return;
  }
  if (tre[rt].l == tre[rt].r) return;
  pushDown(rt);
  int m = (tre[rt].l+tre[rt].r) >> 1;
  if (r <= m)
    update(col, l, r, rt << 1);
  else if (l > m)
    update(col, l, r, rt << 1 | 1);
  else  {
    update(col, l, m, rt << 1);
    update(col, m+1, r, rt << 1 | 1);
  }
}

void query(int l, int r, int rt)
{
  if (tre[rt].col != -1) {
    for (int i = tre[rt].l; i <= tre[rt].r; ++i) {
      col[i] = tre[rt].col;
    }
    tre[rt].col = -1;
    return;
  }
  if (l >= r) return;
  pushDown(rt);
  int m = (tre[rt].l+tre[rt].r) >> 1;
  if (r <= m)
    query(l, r, rt << 1);
  else if (l > m)
    query(l, r, rt << 1 | 1);
  else {
    query(l, m, rt << 1);
    query(m+1, r, rt << 1 | 1);
  }
}

void solve()
{
  memset(col, 0, sizeof col);
  build(0, tot-1, 1);

  int a, b;
  for (int i = 0; i < n; ++i) {
    a = lower_bound(x, x+tot, node[i].x) - x;
    b = lower_bound(x, x+tot, node[i].y) - x;
    update(node[i].col, a, b, 1);
  }

  query(0, tot-1, 1);
  int cnt = 0, st = 0, et = 0, ans = -1, mst = -1, met = -1;

  for (int i = 0; i < tot; ++i) {
    if (col[i] == 1) {
      st = x[i];
      int j = i;
      while (col[j] == 1) {
        et = x[j];
        j++;
      };
    }
    if (et-st > ans) ans = et-st, mst = st, met = et;
  }
  if (mst == met && mst == -1) printf("Oh, my god\n");
  else printf("%d %d\n", mst, met);
}

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  char col;
  int a, b;
  while (scanf("%d", &n) != EOF) {

    tot = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d %d %c", &a, &b, &col);
      x[tot++] = a;
      x[tot++] = b;
      x[tot++] = a+1;
      x[tot++] = a-1;
      x[tot++] = b+1;
      x[tot++] = b-1;
      node[i].x = a;
      node[i].y = b;
      node[i].col = col == 'w'; //w:1 b:0
    }
    sort(x, x+tot);

    tot = unique(x, x+tot) - x;
    solve();
  }
  return 0;
}
