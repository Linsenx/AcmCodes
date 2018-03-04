#include<iostream>
#include<string.h>
#include<string>
//#include<vector>
//#include<stack>
using namespace std;

string a;

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  int i, len, counter;
  while (getline(cin, a)) {
    len = a.size();
    counter = 0;
    for (i = 0; i < len; ++i) {
      if (a[i] == 'i' && a[i+1] == 'f') {
        counter++;
        i++;
      }
    }
    cout << counter << endl;
  }

  return 0;
}
