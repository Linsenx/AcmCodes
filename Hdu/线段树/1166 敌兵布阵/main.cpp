#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;
int kase, tre[4*maxn];

/*
    1[1-10]
 2[1-5] 3[6-10]
*/
void build(int num, int l, int r)
{
  if (l == r)
  {
    cin >> tre[num];
    return;
  }
  int mid = (l+r)/2;
  build(num*2, l, mid);
  build(num*2+1, mid+1, r);
  tre[num] = tre[num*2] + tre[num*2+1];
}

void update(int num, int pos, int add, int l, int r)
{
  if (l == r)
  {
    tre[num] += add;
    return;
  }
  int mid = (l+r)/2;
  if (pos <= mid)
    update(num*2, pos, add, l, mid);
  else 
    update(num*2+1, pos, add, mid+1, r);
  tre[num] = tre[num*2] + tre[num*2+1];
}

//l, r为操作节点 L,R为查询节点
int query(int L, int R, int num, int l, int r)
{
  //cout << l << "," << r << endl;
  //操作节点位于查询节点区间内
  if (L <= l && r <= R)
    return tre[num];

  int mid = (l+r)/2;
  if (R <= mid) //结果在左子树
    return query(L, R, num*2, l, mid);
  if (L > mid) //结果在右子树
    return query(L, R, num*2+1, mid+1, r);
  //左右两边都有
  return query(L, R, num*2, l, mid) + query(L, R, num*2+1, mid+1, r);
}

int main()
{
  ios::sync_with_stdio(false);  
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int test, n;
  cin >> test;
  while (test--) 
  {
    memset(tre, 0, sizeof tre);
    cin >> n;
    build(1, 1, n);
    int a, b;
    string command;
    cout << "Case " << ++kase << ":" << endl;
    while (cin >> command) 
    {
      if (command == "End") break;
      cin >> a >> b;
      if (command == "Add")
        update(1, a, b, 1, n);
      else if (command == "Sub")
        update(1, a, -b, 1, n);
      else if (command == "Query")
        cout << query(a, b, 1, 1, n) << endl;
    }
  }

  return 0;
}
