#include <bits/stdc++.h>
using namespace std;



void makemap()
{
  vector<long long>fibs;

  fibs.push_back(7);
  fibs.push_back(11);
  int cnt = 2;
  while(fibs.size() < 50) {
    fibs.push_back(fibs[cnt-1] + fibs[cnt-2]);
    cnt ++;
  }
  int ind = 0;
  for (auto i : fibs) {
    cout << ind++ << " : " << ((i % 3) == 0) << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  // makemap();
  int n;
  while (cin >> n) {
    if ((n-2) % 4 == 0) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
