#include <iostream>
using namespace std;

int main()
{
  //freopen("in.txt","r",stdin);

  //3+1 30Ԫ4ƿ = 7.5
  //5+2 50Ԫ7ƿ = 7.14
  int money, num;
  num = 0;
  cin >> money;
  while (money >= 50) {
    money -= 50;
    num += 7;
  }
  while (money >= 30) {
    money -= 30;
    num += 4;
  }
  while (money >= 10) {
    money -= 10;
    num += 1;
  }
  cout << num << endl;

  return 0;
}
