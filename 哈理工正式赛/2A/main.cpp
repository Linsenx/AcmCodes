#include<iostream>
#include<string.h>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int n, t;

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  int i, worktime , flag;
  while (cin >> n >> t) {
    flag = 0;
    for (i = 0; i < n; ++i) {
      cin >> worktime;
      int lefttime = 86400 - worktime;
      t -= lefttime;
      if (t <= 0 && flag == 0) {
        flag = 1;
        cout << (i+1) << endl;
        continue;
      }
    }
    if (flag == 0) {
      cout << 0 << endl;
    }
  }

  return 0;
}
