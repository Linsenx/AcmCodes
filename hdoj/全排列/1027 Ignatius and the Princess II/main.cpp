#include <bits/stdc++.h>
using namespace std;

int a[1100];
int N, M;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> N >> M) {
    for (int i = 0; i < N; ++i) a[i] = i + 1;
    for (int j = 0; j < M-1; ++j) next_permutation(a, a+N);
    cout << a[0];
    for (int i = 1; i < N; ++i) cout << ' ' << a[i];
    cout << endl;
  }

  return 0;
}
