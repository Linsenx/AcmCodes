#include <bits/stdc++.h>
using namespace std;

bool isvowel(char x)
{
  return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  string str;
  while (cin >> str && str != "end") {
    int flag = 1;
    int vowel_count = 0;
    int consecutive = 0;
    for (int i = 0; i < str.size(); ++i) {
      if (i < str.size() - 1 && str[i] == str[i + 1]) {
        if (str[i] != 'e' && str[i] != 'o') {
          flag = 0;
          break;
        }
      }
      consecutive = 1;
      if (isvowel(str[i])) {
        vowel_count++;
        for (int j = i + 1; isvowel(str[j]) && j < str.size(); ++j, ++consecutive);
        if (consecutive >= 3) { flag = 0; break; }
      } else {
        for (int j = i + 1; !isvowel(str[j]) && j < str.size(); ++j, ++consecutive);
        if (consecutive >= 3) { flag = 0; break; }
      }
    }
    if (vowel_count == 0) flag = 0;
    string k = flag ? " is acceptable." : " is not acceptable.";
    cout << '<' << str << '>' << k << endl;
  }

  return 0;
}
