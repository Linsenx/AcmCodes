#include<iostream>
#include<string.h>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int N;
int si[1050];
int di[1050];

void solve()
{
  int d_index = 0;
  int start_day = si[d_index];

  int j;
  for (d_index = 1; d_index < N; ++d_index) {
    for (j = 0; si[d_index] + j*di[d_index] <= start_day; ++j);
    start_day = si[d_index] + j*di[d_index];
  }
  cout << start_day << endl;
}

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  int i, j;
  while (cin >> N) {
    for (i = 0; i < N; ++i) {
      cin >> si[i];
      cin >> di[i];
    }
    solve();
  }

  return 0;
}
