#include <bits/stdc++.h>
using namespace std;

struct stra {
  vector<string>s;
};


string sortstr(string str)
{
  char a;
  int len = str.size();
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++ j) {
      if (str[i] >= str[j]) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
      }
    }
  }
  return str;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  map<string,stra>dic;
  // dictionary
  string str;
  while (cin >> str && str != "XXXXXX") {
    dic[sortstr(str)].s.push_back(str);
    sort(dic[sortstr(str)].s.begin(), dic[sortstr(str)].s.end());
  }
  
  //scrambled
  while (cin >> str && str != "XXXXXX") {
    if (dic[sortstr(str)].s.size() > 0) {
      for (int i = 0; i < dic[sortstr(str)].s.size(); ++i) {
        cout << dic[sortstr(str)].s[i] << endl;
      }
      cout << "******" << endl;
    } else {
      cout << "NOT A VALID WORD" << endl;
      cout << "******" << endl;
    }
  }
  
  
  return 0;
}
