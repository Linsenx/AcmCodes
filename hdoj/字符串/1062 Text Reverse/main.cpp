#include <bits/stdc++.h>
using namespace std;

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int N, i, j;
  string line;
  string word;
  cin >> N;
  getchar();
  while (N--) {
    getline(cin, line);
    for (i = 0; i < line.size(); ++i) {
      if (line[i] != ' ') {
        word.clear();
        word += line[i];
        for (j = i + 1; j < line.size() && line[j] != ' '; ++j, ++i) {
          word += line[j];
        }
        string new_word = string(word.rbegin(), word.rend());
        cout << new_word;
      }
      else {
        cout << ' ';
      }
    }
    cout << endl;
  }


  return 0;
}
