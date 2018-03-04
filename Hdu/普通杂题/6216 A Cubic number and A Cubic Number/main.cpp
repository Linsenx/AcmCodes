#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> tb;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  for (int i = 1; i <= 1e6 + 10; ++i) {
    ll v = 3ll*i*i + 3ll*i + 1ll;
    tb.push_back(v);
  }
  
  int test;
  ll p;
  cin >> test;
  while (test--) {
    cin >> p;
    if (binary_search(tb.begin(), tb.end(), p)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
