#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[1000100];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> k >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    
    int min_milk = a[0];
    int max_milk = a[n-1];
    if (k >= min_milk && k <= max_milk) {
      
    } else {
      cout << -1 << endl;
    }
    
  }

  return 0;
}
