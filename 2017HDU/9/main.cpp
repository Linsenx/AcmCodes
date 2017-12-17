#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
int N,M;
unsigned long long A[110000];
unsigned long long B[110000];

int main()
{

    #ifdef ONLINE_JUDGE
    #else
      freopen("in.txt","r",stdin);
    #endif

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int v = 0; v < M; ++v) {
      cin >> B[v];
    }
    sort(A, A+N);
    sort(B, B+M);
    unsigned long long sum = 0;
    if (N < M) {
      for (int j = 0; j < N; ++j) {
        sum += A[N-j-1]*B[M-j-1];
      }
    } else {
      for (int k = 0; k < M; ++k) {
        sum += A[N-k-1]*B[M-k-1];
      }
    }
    cout << min(N,M) << " " << sum << endl;
  return 0;
}
