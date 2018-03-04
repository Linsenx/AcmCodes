#include <bits/stdc++.h>
using namespace std;

int N, x, magic;
int counter[1000100];
int keymaps[1000100];

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (scanf("%d", &N) != EOF) {
    memset(counter, 0, N+100);
    memset(keymaps, 0, N+100);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &x);
      counter[x] ++;
      keymaps[counter[x]] = x;
    }
    magic = (N+1)/2;
    printf("%d\n", keymaps[magic]);
  }

  return 0;
}
