#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  string p, str;
  map<string,int> m;
  while (getline(cin, p) && p != "#")
  {
    m.clear();
    for (int i = 0; i < p.size()+1; ++i) {

      if (p[i] >= 'a' && p[i] <= 'z') {
        str += p[i];
      }
      else {
        if (str.size() > 0) {
          m[str]++;
        }

        str.clear();
      }
    }
    cout << m.size() << endl;
  }


  return 0;
}
