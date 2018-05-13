#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL t, n, m;
LL a[20], b[20];

LL exgcd(LL a, LL b, LL& x, LL& y)
{
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  LL tx, ty;
  LL d = exgcd(b, a%b, tx, ty);
  x = ty;
  y = tx - (a/b)*ty;
  return d;
}

void work()
{
  LL a1, b1, tx, ty, d;
  a1 = a[1]; b1 = b[1];
  for (int i = 2; i <= m; ++i) {
    d = exgcd(a1, a[i], tx, ty);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
  }

  return 0;
}
