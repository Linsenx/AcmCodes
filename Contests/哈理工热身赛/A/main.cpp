#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> kk;

int main()
{
//  ios::sync_with_stdio(false);
  freopen("in.txt","r",stdin);

  while (cin >> N >> M) {
    kk.clear();
    int i, x;
    for (i = 0; i < N; ++i) {
      cin >> x;
      if (x != M) {
        kk.push_back(x);
      }
    }
    cout << kk.size() << endl;
    for (i = 0; i < kk.size(); ++i) {
      cout << kk[i];
      if (i != kk.size()-1) cout << ' ';
    }
    cout << endl;
  }

  return 0;
}
