#include <bits/stdc++.h>
using namespace std;

int gifts[25];
int books[25];
int n, k;
bool flag = false;

void dfs(int k)
{
  if (flag|| k < 0) {
    return;
  }
  if (flag || k == 0) {
    flag = true;
    return;
  }
  
  int *it = lower_bound(gifts, gifts+n, k);
  if (*it == k) {
    flag = true;
    return;
  }
    
  for (int i = 0; i < n && !flag; ++i) {
    if (books[i] == 0) {
      books[i] = -1;
      dfs(k - gifts[i]);
      books[i] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (cin >> n >> k) {
    flag = false;
    memset(gifts, 0, 25);
    memset(books, 0, 25);
    for (int i = 0; i < n; ++i) cin >> gifts[i];
    sort(gifts, gifts+n);
    
    if (n * gifts[n-1] > k) {
      dfs(k);
    }
    
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
