#include <bits/stdc++.h>
using namespace std;

map<string, string> dic;
string a, b;
char str0[20];
char str[10000];

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  cin >> a;
  while (cin >> a && a != "END") {
    cin >> b;
    dic[b] = a;
  }

  cin >> a; //START
  string word;
  getchar();
  while (gets(str)) {
    if (!strcmp(str, "END")) break;
    for (int i = 0; i < strlen(str); ++i) {
      if (str[i] >= 'a' && str[i] <= 'z') {
        int j = 0;
        for (j = i; j < strlen(str) && str[i] >= 'a' && str[i] <= 'z'; ++j, ++i) {
          word += str[j];
        }
        if (dic[word] != "") {
          cout << dic[word];
        }
        else {
          cout << word;
        }
        cout << str[j];
      } else {
        cout << str[i];
      }
      word.clear();
    }
    printf("\n");
  }

  return 0;
}
