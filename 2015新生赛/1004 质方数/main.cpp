#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10007;
int prime[MAXN], index = -1;
int zfs[1500];//1229

void getprime()
{
  prime[1] = 1; //不是素数
  prime[2] = 0; //是素数
  for (int i = 2; i < MAXN; ++i) {
    if (prime[i] == 0) {
      zfs[index++] = i*i;
      for (int j = i+i; j < MAXN; j += i) prime[j] = 1;
    }
  }


}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  getprime();

  int N, x;
  cin >> N;
  while (N--) {
    cin >> x;
    int pos = lower_bound(zfs, zfs+1229, x) - zfs;
    if (abs(zfs[pos] - x) < abs(zfs[pos-1] - x)) {
      cout << zfs[pos] << endl;
    } else {
      cout << zfs[pos-1] << endl;
    }
  }

  return 0;
}
