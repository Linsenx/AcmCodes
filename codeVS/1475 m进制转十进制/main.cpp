#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);
  string n;//数值
  int m; //进制
  cin >> n >> m;
  int num = 0; //10进制数
  int v = n.size();//数值长度
  for(int i = 0; i < v; ++i) {
      if (n[i] >= '0' && n[i] <= '9') {
          int val = n[i] - '0';
          if (val > 0) num += val*pow(m, (v-1-i));
      } else if(n[i] >= 'A' && n[i] <= 'F') {
          int val = n[i] - 'A' + 10;
          if (val > 0) num += val*pow(m, (v-1-i));
      }
  }
  cout << num << endl;
  return 0;
}
