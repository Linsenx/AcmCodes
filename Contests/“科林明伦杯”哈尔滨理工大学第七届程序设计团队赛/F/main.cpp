#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int cmp(string a, string b)
{
  return a.size() > b.size();
}

int main()
{
  //ios::sync_with_stdio(false);
  freopen("in.txt","r",stdin);

  int i, j, n, kase;
  kase = 0;
  while (cin >> n) {
    int times = 0;
    bool p_G = false, p_X = false, p_Z = false;
    vector<string> poison;
    for (i = 0; i < n; ++i) {
      string str;
      cin >> str;
      if (str == "G") p_G = true;
      if (str == "X") p_X = true;
      if (str == "Z") p_Z = true;
      poison.push_back(str);
    }
    sort(poison.begin(), poison.end(), cmp);
    string n_fix;
    cin >> n_fix;
    if (p_G && p_X && p_Z) {
      cout << "Case " << ++kase << ": " << -1 << endl;
    } else {
      int index;
      string p_str;
      for (i = 0; i < poison.size(); ++i) {
        p_str = poison[i];
        while (n_fix.find(p_str) != string::npos) {
          index = n_fix.find(p_str);
          for (j = index; j < index + p_str.size(); ++j) {
            n_fix[j] = 'O';
          }
          times++;
        }
      }

      cout << "Case " << ++kase << ": " << times << endl;
    }
  }


  return 0;
}
