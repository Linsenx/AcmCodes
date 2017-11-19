#include<iostream>
#include<string.h>
#include<math.h>
#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int tonum(char a)
{
  if (a == 'I') return 1;
  else if (a == 'V') return 5;
  else if (a == 'X') return 10;
  else if (a == 'L') return 50;
  else if (a == 'C') return 100;
  else if (a == 'D') return 500;
  else if (a == 'M') return 1000;
  else return 0;
}

void trans(string x)
{
  int i;
  int cnt = 0;
  int len = x.size();
  for (i = 0; i < len; ++i) {
    //×ó´óÓÒÐ¡
    if (i+1 >= x.size() || tonum(x[i+1]) <= tonum(x[i])) {
      cnt += tonum(x[i]);
    }
    else {
      cnt -= tonum(x[i]);
    }
  }
  cout << cnt << endl;
}

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  string x;
  while (cin >> x) {
    trans(x);
  }

  return 0;
}
