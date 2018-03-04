#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int n, m, tre[maxn << 2];
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1

void pushUp(int rt)
{
  tre[rt] = tre[rt << 1] && tre[rt << 1 | 1] ? tre[rt << 1] + tre[rt << 1 | 1] : 0;
}

void build(int l, int r, int rt)
{
  if (l == r) 
  {
    tre[rt] = 1;
    return;
  }
  int m = (l+r) >> 1;
  build(lson);
  build(rson);
  pushUp(rt);
}

void update(int p, int change, int l, int r, int rt)
{
  
  if (l == r)
  {
    tre[rt] = change;
    return;
  }
  int m = (l+r) >> 1;
  
  if (p <= m)
    update(p, change, lson);
  else
    update(p, change, rson);
  pushUp(rt);
}

int query(int L, int R, int l, int r, int rt)
{
  if (l == r)
  {
    cout << l << ":" << tre[rt] << endl;
    return tre[rt];
  }
  int m = (l+r) >> 1;
  int res0 = 0, res1 = 0;
  if (R <= m)
    res0 = query(L, R, lson);
  else if (m < L)
    res1 = query(L, R, rson);
  else 
  {
    res0 = query(L, R, lson);
    res1 = query(L, R, rson);
    return res0 && res1 ? res0+res1 : 0;
  }
  return res0 + res1;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
//  build(1,4,1);
//  update(1,0,1,4,1);
//  update(2,1,1,4,1);
//  update(3,1,1,4,1);
//  update(4,1,1,4,1);
//  cout << query(1,4,1,4,1) ;
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
        update(a, 0, 1, n, 1);
      }
      else if (comm == 'R')
      {
        b = destory.top(); destory.pop();
        update(b, 1, 1, n, 1)
      }
      else if (comm == 'Q')
      {
        cin >> a;
        int l = query()
      }
    }
  }
  
  return 0;
}
