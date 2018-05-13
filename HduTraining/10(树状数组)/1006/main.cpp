#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll __int64

const int maxn = 20000 + 100;
ll _sum[maxn], _cnt[maxn], n = maxn;
unsigned long long total;

ll lowbits(ll x)
{
  return x & (-x);
}

//x: 距离 cnt: 头数
void add(ll x, ll cnt)
{
  total += x;
  for (ll i = x; i <= n; i += lowbits(i)) {
    _sum[i] += x;
    _cnt[i] += cnt;
  }
}

ll getCnt(ll x)
{
  ll ans = 0;
  for (ll i = x; i > 0; i -= lowbits(i)) {
    ans += _cnt[i];
  }
  return ans;
}

ll getSum(ll x)
{
  ll ans = 0;
  for (ll i = x; i > 0; i -= lowbits(i)) {
    ans += _sum[i];
  }
  return ans;
}

struct cow {
  ll v, x;
} cows[maxn];

bool cmp(const cow a, const cow b)
{
  return a.v < b.v;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int m;
  cin >> m;
  total = 0;
  memset(_sum, 0, sizeof(_sum));
  memset(_cnt, 0, sizeof(_cnt));
  
  for (int i = 0; i < m; ++i) {
    cin >> cows[i].v >> cows[i].x;
  }
  sort(cows, cows+m, cmp);
  
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    ll cntright, cntleft, sumright, sumleft;
    cntleft = getCnt(cows[i].x);
    cntright = i - cntleft;
    sumleft = getSum(cows[i].x);
    sumright = total - sumleft;
    ans += cows[i].v * (sumright - cntright*cows[i].x + cntleft*cows[i].x - sumleft);
    add(cows[i].x, 1);
  }
  cout << ans << endl;


  return 0;
}


// v*(a-x) + v*(b-x) + v*(c-x)
// v * (sum(right) - cnt(right) * x)

// v*(x-e) + v*(x-f) + v*(x-g)
// v * (sum(left) - cnt(left) * x)

// All = v * ( (sum(right) - cnt(right) * x) + (-sum(left) cnt(left) * x) );
//一个树状数组按坐标存所有牛离原点的距离和
//一个树状数组按坐标存牛的头数

//先把所有牛按耳背程度升序排列
//每次加入一头牛，从树状数组取该牛左右牛的头数，左右牛的距离和


