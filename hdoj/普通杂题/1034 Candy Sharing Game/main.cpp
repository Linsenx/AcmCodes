#include <bits/stdc++.h>
using namespace std;

int isequal(int N, int a[])
{
  int i;
  for (i = 0; a[i] == a[0]; ++i);
  return i == N;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int N, rounds;
  while (cin >> N && N != 0) {
    int candy[N], tmp[N];
    for (int i = 0; i < N; ++i) cin >> candy[i];
    
    rounds = 0;
    while (!isequal(N, candy)) {
      for (int i = 0; i < N; ++i) tmp[i] = candy[i]/2;
      for (int j = 0; j < N; ++j) {
        if (j > 0)
          candy[j] = candy[j]/2 + tmp[j-1];
        else
          candy[j] = candy[j]/2 + tmp[N-1];
        if (candy[j] % 2 == 1) candy[j] += 1;
      }
      rounds ++;
    }
    cout << rounds << ' ' << candy[0] << endl;
  }
  
  return 0;
}
