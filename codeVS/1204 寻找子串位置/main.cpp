#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int first;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == s2[0]) {
      first = i;
      for(int j = 0; s1[i+j] == s2[j]; ++j)
      if (j == s2.size()-1) {
          cout << first+1 << endl;
          return 0;
      }
    }
  }
  return 0;
}
