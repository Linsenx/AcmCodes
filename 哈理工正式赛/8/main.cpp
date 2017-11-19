#include<iostream>
#include<string.h>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int dfs(int a, int x, int left)
{

  if (x < 0) return 0;
  if (x == 0) {
    return 1;
  }

  int i, counter;
  counter = 0;
  for (i = left+1; i < a; ++i) {
    counter += dfs(a, x-i, i);
  }

  return counter;
}

void solve(int x)
{
  int i, j, k, chose, cnt, tmp, ll;
  cnt = 0;
  ll = (x / 2) + 1;
  chose = 2;
  for (i = ll; i >= 0; --i) {
    tmp = x;
    for (k = ll; k >= 0; --k) {
      if (k-chose+1 >= 1 && tmp == ((k+(k-chose+1))*chose)/2) {
        //cout << k << '=' << k-chose+1 << "=>" <<((k+(k-chose+1))*chose)/2 << endl;
        cnt++;
        break;
      }
    }
    chose++;
    /*tmp = x;
    tmp = tmp - i;
    for (j = i + 1; tmp > 0 ;++j) {
      tmp = tmp - j;
    }
    if (tmp == 0) cnt++;*/
  }
  cout << "res:" <<cnt << endl;

  //cout << dfs(x, 0) << endl;
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
