#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 100;
int w, h, k, tre[maxn << 2];
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1

void pushUp(int rt)
{
  tre[rt] = max(tre[rt << 1], tre[rt << 1 | 1]);
}

void build(int w, int l, int r, int rt)
{
  tre[rt] = w;
  if (l == r) return;
  int m = (l+r)/2;
  build(w, lson);
  build(w, rson);
}

int query(int w, int l, int r, int rt)
{
  if (l == r)
  {
    tre[rt] -= w;
    return l;
  }
  int m = (l+r)/2;
  int ret = -1;
  if (tre[rt<<1] >= w)
    ret = query(w, lson);
  else
    ret = query(w, rson);
  pushUp(rt);
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int q;
  while (cin >> h >> w >> k)
  {
    if (h > k) h = k;
    build(w, 1, h, 1);
    while (k--)
    {
      cin >> q;
      if (tre[1] < q) cout << -1 << endl;
      else cout << query(q, 1, h, 1) << endl;
//      cout << query(q, 1, h, 1) << endl;
    }
  }

  return 0;
}
