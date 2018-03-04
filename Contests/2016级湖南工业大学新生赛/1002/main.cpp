#include <bits/stdc++.h>
using namespace std;

int n, k, flag;
int nums[160];
int r[2];
int d_min;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> n >> k) {
    flag = 0;
    d_min = -1;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    //sort(nums, nums + n);

    for (int j = 0; j < n; ++j) {
      for (int l = j+1; l < n; ++l) {
        if (nums[j] + nums[l] == k) {
          flag = 1;
          if (d_min == -1 || max(nums[j], nums[l])-min(nums[j], nums[l]) < d_min) {
            r[0] = min(nums[j], nums[l]);
            r[1] = max(nums[j], nums[l]);
            d_min = r[1] - r[0];
          }
        }
      }
    }

    if (!flag) cout << -1 << endl;
    else cout << r[0] << ' ' << r[1] << endl;
  }

  return 0;
}
