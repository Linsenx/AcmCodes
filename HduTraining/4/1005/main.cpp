#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 10000 + 10;
const int maxbase = 60; //10^18 = 2^(59.xxxx) 

int T, N, Q, KASE;
bool haszero = false;
ll a[maxn], b[maxbase + 10];
vector<ll> basev;

void Gauss()
{
  int cnt = 0;
  memset(b, 0, sizeof b);
  
  for (int i = 0; i < N; ++i)
    for (int j = maxbase; j >= 0; j--) {
      if ((a[i] >> j) & 1) {
        if (b[j]) a[i] ^= b[j];
        else {
          cnt ++;
          b[j] = a[i];
          //保持对角阵
          //用下面的行消自己
          for (int k = j - 1; k >= 0; --k) if (b[k] && (b[j] >> k) & 1) b[j] ^= b[k];
          //用自己消下面的行
          for (int k = j + 1; k <= maxbase; ++k) if ((b[k] >> j) & 1) b[k] ^= b[j];
          break;
        }
      }
    }
    if (cnt != N) haszero = true;
    
    for (int j = 0; j <= maxbase; ++j)
      if (b[j]) basev.push_back(b[j]);
}

ll query(ll q)
{
  if (haszero) q--;
  if (q > (1ll << basev.size()) - 1) return -1;
  
  ll ans = 0;
  for (int i = 0; i < basev.size(); ++i)
    if ((q >> i) & 1) ans ^= basev[i];
  return ans;
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  scanf("%d", &T);
  while (T--) {
    haszero = false;
    basev.clear();
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%I64d", &a[i]);
    Gauss();
    
    scanf("%d", &Q);
    printf("Case #%d:\n", ++KASE);
    while (Q--) {
      int q;
      scanf("%I64d", &q);
      printf("%I64d\n", query(q));
    }
  }

  return 0;
}
