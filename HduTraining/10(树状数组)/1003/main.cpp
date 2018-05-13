#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e6;

ll n, c[MAXN];
struct node {
  int data;
  int pos;
}s[MAXN];

bool cmp(node x,node y)
{
  return x.data<y.data;
}

ll lowbit(ll x)
{
  return x & (-x);
}

ll modify(ll x, ll add)
{
  while (x <= n) {
    c[x] += add;
    x += lowbit(x);
  }
}

ll getSum(ll x)
{
  ll ans = 0;
  while (x > 0) {
    ans += c[x];
    x -= lowbit(x);
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int x;
  ll cnt = 0;
  while (cin >> n) {
    cnt = 0;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; ++i) {
      cin >> s[i].data;
      s[i].pos = i;
    }
    sort(s+1, s+1+n, cmp);

    for (int i = n; i > 0; --i) {
      cnt += getSum(s[i].pos);
      modify(s[i].pos, 1);
    }
    cout << cnt << endl;
  }



  return 0;
}
