#include<stdio.h>
#include<iostream>
#include<string.h>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int main()
{
//  ios::sync_with_stdio(false);
  freopen("in.txt","r",stdin);

  int i, N, x, aa, n_min, n_max;
  n_min = 0;
  n_max = 0;
  aa = 0;
  long long sum;
  long long lostone;
  while (scanf("%d", &N) != EOF) {
    sum = 0;
    for (i = 0; i < N; ++i) {
      scanf("%d", &x);
      if (x >= 0) {
        if (i == 0) n_min = x, n_max = x;
        n_min = min(n_min, x);
        n_max = max(n_max, x);
        sum += x;
        aa++;
      }
    }

    lostone = ((n_min+aa)*(aa))/2 - sum;
    cout << lostone <<endl;

  }
  /*unsigned long long l;
  for (int i = 0; i < 1000000; ++i) {
    l += +i;
  }
  cout << l;*/

  return 0;
}
