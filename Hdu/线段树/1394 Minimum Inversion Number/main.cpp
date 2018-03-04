#include <bits/stdc++.h>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
const int maxn = 5e3 + 10;
int tre[maxn << 2], a[maxn];

void pushUp(int rt)
{
  tre[rt] = tre[rt << 1] + tre[rt << 1 | 1];
}

void build(int l, int r, int rt)
{
  if (l == r)
  {
    tre[rt] = 0;
    return;
  }
  int m = (l+r)/2;
  build(lson);
  build(rson);
  pushUp(rt);
}

void update(int p, int l, int r, int rt)
{
  if (l == r)
  {
    tre[rt] ++;
    return;
  }
  int m = (l+r)/2;
  if (p <= m)
    update(p, lson);
  else 
    update(p, rson);
  pushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
  if (L <= l && r <= R)
  {
    return tre[rt];
  }
  int m = (l+r)/2;
  if (m >= R)
    return query(L, R, lson);
  if (L > m)
    return query(L, R, rson);
  return query(L, R, lson) + query(L, R, rson);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int n, sum;
  while (cin >> n) 
  {
    build(0, n-1, 1);
    sum = 0;
    for (int i = 0; i < n; ++i) 
    {
      cin >> a[i];
      sum += query(a[i], n-1, 0, n-1, 1); //找出a[i]前比a[i]大的数
      update(a[i], 0, n-1, 1);
    }
    int mini = sum;
    for (int i = 0; i < n; ++i) 
    {
      // 3 0 1 2 -> 0 1 2 3 (0~n-1)
      // 逆序队减少a[i]后面比a[i]小的个数, 增加a[i]后比a[i]大的个数
      // sum += - a[i] + (n-1-a[i]) += n - 2*a[i] - 1
      sum += n - 2*a[i] - 1;
      mini = min(sum, mini);
    }
    cout << mini << endl;
  }

  return 0;
}
