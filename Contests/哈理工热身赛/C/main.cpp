#include<iostream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

string save[30];


string Int_to_String(int n)
{
ostringstream stream;
stream<<n;  //nÎªintÀàÐÍ
return stream.str();
}

void getit()
{
  save[0] = "1";

  int s;
  string next;
  int i, j, m;
  for (i = 1; i < 30; ++i) {
    next.clear();
    char ma;
    string str = save[i-1];
    for (j = 0; j < str.size(); ++j) {
      for (m = 1; str[j+m] == str[j]; ++m);
      next += Int_to_String(m);
      next += str[j];
      j = j + m - 1;
    }
    save[i] = next;
  }

}

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  getit();
  int x;
  while (cin >> x) {
    cout << save[x-1] << endl;
  }

  return 0;
}
