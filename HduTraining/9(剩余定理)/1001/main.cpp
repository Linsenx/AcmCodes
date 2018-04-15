#include <bits/stdc++.h>
using namespace std;

void makexyz()
{
  //(d+n)%23=p
  //(d+n)%28=e
  //(d+n)%33=i

  //(28*33*c)%23=1 -> 5544
  //(23*33*b)%28=1 -> 14421
  //(23*28*a)%33=1 -> 1288
  int a = 1;
  while ((23*28*a)%33 != 1) a++;
  cout << (23*28*a) << endl;

  int b = 1;
  while ((23*33*b)%28 != 1) b++;
  cout << (23*33*b) << endl;

  int c = 1;
  while ((28*33*c)%23 != 1) c++;
  cout << (28*33*c) << endl;
}

int kase;
int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  //(28*33*c)%23=1 -> 5544
  //(23*33*b)%28=1 -> 14421
  //(23*28*a)%33=1 -> 1288
  int test, p, e, i, d;
  cin >> test;
  while (test--) {
    kase = 0;
    while (cin >> p >> e >> i >> d) {
      if (p == -1 && e == -1 && i == -1 && d == -1) break;
      int X = (p*5544+e*14421+i*1288) % 21252;
      X-=d;
      while (X <= 0) X+=21252;
      printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, X);
    }
  }

  return 0;
}
