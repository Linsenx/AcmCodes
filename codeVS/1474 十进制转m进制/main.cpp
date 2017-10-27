#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);
  int n, m;
  cin >> n >> m;

  int o = 0; //余数
  vector<int> num;
  while (n >= m) //n能否继续除下去
  {
    o = n % m;
    n = n / m;
    num.insert(num.begin(), o);
  }
  num.insert(num.begin(), n);

  for (int i = 0; i < num.size(); ++i) {
      if (num[i] >= 10) cout << (char)(num[i]-10+65);
      else cout << num[i];
  }

  return 0;
}
