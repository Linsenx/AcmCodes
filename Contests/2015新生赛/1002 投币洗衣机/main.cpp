#include <bits/stdc++.h>
using namespace std;




int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int n, a, b, c, x, sum, cost;
  while(cin >> n >> a >> b >> c) {
    sum = 0;
    cost = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      sum += x;
      if (sum >= a && sum < b) {
        cost += 2;
        sum = 0;
      } else if (sum >= b && sum < c) {
        cost += 3;
        sum = 0;
      } else if (sum >= c){
        cost += 4;
        sum = 0;
      }
    }
    cout << cost << endl;
  }

  return 0;
}
