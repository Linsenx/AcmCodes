#include <bits/stdc++.h>
using namespace std;

bool isLeapyear(int Y)
{
  return (Y%4 == 0 && Y%100 != 0) || Y%400 == 0;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n, Y, N, NY, cnt;
  cin >> n;
  while (n--) {
    cin >> Y >> N;
    cnt = 0;
    NY = Y - 1;
    while (cnt < N) {
      NY ++;
      if (isLeapyear(NY)) cnt++;
    }
    cout << NY << endl;
  }

  return 0;
}
