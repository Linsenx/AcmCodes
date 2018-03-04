#include <bits/stdc++.h>
using namespace std;

vector<int>a;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int x, n;
  while (cin >> n && n != 0) {
    a.clear();
    for (int i = 0; i < n; ++i) cin >> x, a.push_back(x);
    sort(a.begin(), a.end());
    
    int c = 1;
    for (int i = n; i > 1; --i) c*=i;
    
    for (int i = 0; i < c; ++i) {
      for (int k = 0; k < a.size(); ++k) cout << " " << a[k];
      cout << endl;
      next_permutation(a.begin(), a.end());
    }
    cout << "sum:" << c << endl;
    
  }

  return 0;
}
