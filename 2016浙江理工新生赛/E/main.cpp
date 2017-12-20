#include <bits/stdc++.h>
using namespace std;
int days[2] = {355, 356};
int month[2][12] =
{
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

int isspecial(int y)
{
  return (y%400==0)||(y%4==0 && y%100!=0);
}

int todays(int y, int m, int d)
{
  //1900-1-1 =>y-m-d
  int sum = 0;
  int delta = y - 1900;
  for (int i = 0; i < delta; ++i) {

  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  //2017-1-1 -> 2017-10-28
  int T, Y, M, D, SUM;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> Y >> M >> D;
    SUM = 0;
    //2017 1 6
    if (Y == 2017 && M == 10) {
      SUM = 28 - D;
    } else {
      //先计算到下一个月1号
      SUM += 1+month[isspecial(Y)][M-1] - D;
      M = M + 1;
      D = 0;
      if (M > 12) {
        M = 1;
        Y = Y + 1;
      }
      while (Y < 2017 || M < 10) {
        SUM += month[isspecial(Y)][M-1];
        M++;
        if (M > 12) {
          M = 1;
          Y = Y + 1;
        }
      }
      SUM += 27;
    }
    cout << SUM << endl;
  }

  return 0;
}
