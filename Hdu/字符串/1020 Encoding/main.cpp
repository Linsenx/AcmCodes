#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int N;
  string str, new_str;
  cin >> N;
  while (N--) {
    cin >> str;
    new_str.clear();
    for (int i = 0; i < str.size(); ++i) {
      int j = 0, cnt = 1;
      for (j = i + 1; str[j] == str[i]; ++ j, ++i, ++cnt);
      if (cnt > 1) new_str += to_string(cnt);
      new_str += str[i];
    }
    cout << new_str << endl;
  }

  return 0;
}
