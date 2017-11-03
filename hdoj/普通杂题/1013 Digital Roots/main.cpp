#include <bits/stdc++.h>
using namespace std;

int solve(string x)
{
  int sum = 0;
  for (auto i:x) {
    sum += (int)(i - '0');
  }
    if (sum < 10) 
    return sum;
  else
    return solve(to_string(sum));
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  string x;
  while (cin >> x && x != "0") {
    cout << solve(x) << endl;
  }
  
  return 0;
}
