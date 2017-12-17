#include<iostream>
#include<string.h>
using namespace std;

void solve(int n)
{
  int cnt = 0;
  int k1, k2, x;
  
  for (int i = 1; (k1 = i*(i-1)/2) <= n; ++i) {
    k2 = n - k1;
    //当找到0开头的等差数列时，跳出循环
    if (k2 == 0) break; 
    //根据等差数列公式 n = x*i + i*(i-1)/2
    if (k2 % i == 0) {
      cnt++;
    }
  }
  cout << cnt - 1 << endl;
}

int main()
{
//  ios::sync_with_stdio(false);
  freopen("in.txt","r",stdin);

  int x;
  while (cin >> x) {
    solve(x);
  }

  return 0;
}
