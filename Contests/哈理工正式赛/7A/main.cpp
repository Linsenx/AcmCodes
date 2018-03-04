#include<iostream>
#include<string.h>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int len;
string x;

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  int i, bg, ed, times, flag;
  while (cin >> x) {
    flag = 1;
    len = x.size();
    times = len / 2;
    bg = 0;
    ed = len-1;
    for (i = 0; i < times && flag == 1; ++i) {
      if (x[bg] != x[ed]) {
        flag = -1;
        break;
      }
      bg ++;
      ed --;
    }
    if (flag == 1) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
