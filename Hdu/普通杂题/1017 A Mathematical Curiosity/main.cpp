#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m)
{
  int sum = 0;
  for (int a = 1; a < n; ++a) 
  {
    for (int b = a + 1; b < n; ++b) 
    {
      if ((a*a+b*b+m) % (a*b) == 0) 
      {
        ++ sum;
      }
    }
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int N, n, m, CASE;
  cin >> N;
  while (N--) {
    CASE = 0;
    while (cin >> n >> m && (m+n)) {
      cout << "Case " << ++CASE << ": " << solve(n, m) << endl;
    }
    if (N != 0) cout << endl;
  }

  return 0;
}
