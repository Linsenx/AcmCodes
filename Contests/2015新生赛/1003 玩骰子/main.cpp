#include <bits/stdc++.h>
using namespace std;

int judge(int a, int b, int c, int d, int e, int f)
{
  int state_N, state_A;
  int value_N, value_A;
  //N
  if (a == b && b == c) state_N = 3, value_N = a; //三条
  else if (a == b) state_N = 2, value_N = a;      //对子
  else if (a == c) state_N = 2, value_N = a;      //对子
  else if (b == c) state_N = 2, value_N = b;      //对子
  else state_N = 1;

  //A
  if (d == e && e == f) state_A = 3, value_A = d;
  else if (d == e) state_A = 2, value_A = d;
  else if (d == f) state_A = 2, value_A = d;
  else if (e == f) state_A = 2, value_A = e;
  else state_A = 1;

  if (state_N > state_A) {
      return 1;
  }
  else if (state_N == state_A) {
    if (state_N == 3 && value_N > value_A) return 1;
    else if (state_N == 2) {
      if (value_N > value_A) return 1;
      else if (value_N == value_A && ((a+b+c-2*value_N)>(d+e+f-2*value_A))) return 1;
    }
    else if (state_N == 1) {
      int sum_N = a+b+c;
      int max_N = max(max(a,b),c);
      int min_N = min(min(a,b),c);
      int sum_A = d+e+f;
      int max_A = max(max(d,e),f);
      int min_A = min(min(d,e),f);

      if (max_N > max_A) return 1;
      else if (max_N == max_A) {
        if (sum_N - max_N - min_N > sum_A - max_A - min_A) return 1;
        else if (sum_N - max_N - min_N == sum_A - max_A - min_A && min_N > min_A) return 1;
      }
    }
  }

  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int n, winadd;
  double winrate;
  int a, b, c, d, e, f;
  cin >> n;
  while (n--) {
    winrate = 0;
    cin >> a >> b >> c >> d >> e >> f;
    if (judge(a,b,c,d,e,f) == 0) {
      winadd = 0;
      for (int i = 1; i <= 6; ++i) { //换a
        winadd += judge(i,b,c,d,e,f);
      }
      winrate = max(winrate,winadd*1.0/6);

      winadd = 0;
      for (int j = 1; j <= 6; ++j) { //换b
        winadd += judge(a,j,c,d,e,f);
      }
      winrate = max(winrate,winadd*1.0/6);

      winadd = 0;
      for (int k = 1; k <= 6; ++k) { //换c
        winadd += judge(a,b,k,d,e,f);
      }
      winrate = max(winrate,winadd*1.0/6);
    } else {
      winrate = 1;
    }
    cout << fixed << setprecision(3) << winrate << endl;
  }

  return 0;
}
