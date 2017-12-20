#include <bits/stdc++.h>
using namespace std;

int N;
string input;
string example;
string input_w;
string example_w;


int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  b  
  while (cin >> N) {
    string line;
    int cnt = 0;
    int type = 0;
    getchar();
    while (getline(cin, line)) {
      if (line != "START" && line != "END") {
        if (type == 0) {
          example += line + "\n";
        }
        else {
          input += line + "\n";
        }
      } else if (line == "END") {
        if (type == 0) type = 1;
        else {
          for (int i = 0; i < example.size(); ++i) {
            if (example[i] != ' ' && example[i] != '\n' && example[i] != '\t') example_w += example[i];
          }
          for (int i = 0; i < input.size(); ++i) {
            if (input[i] != ' ' && input[i] != '\n' && input[i] != '\t') input_w += input[i];
          }   
          //比较处理
          //cout << example << endl << input << endl;
          if (!strcmp(example.c_str(), input.c_str())) {
            cout << "Accepted" << endl;
          } else if (!(strcmp(example_w.c_str(), input_w.c_str()))) {
            cout << "Presentation Error" << endl;
          } else {
            cout << "Wrong Answer" << endl;
          }
          type = 0;
          //初始化
          input.clear();
          input_w.clear();
          example.clear();
          example_w.clear();
          //if (N == 0) continue;
        }
      }
    }
  }
  
  return 0;
}
