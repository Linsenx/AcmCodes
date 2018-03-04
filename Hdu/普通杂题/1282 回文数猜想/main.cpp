#include <bits/stdc++.h>
using namespace std;

string saves[1000];

bool check(string x)
{
  bool flag = true;
  int len = x.length();
  for (int i = 0; i < len / 2; ++i) 
  {
    if (x[i] != x[len-1-i])
    {
      flag = false;
      break;
    }
  }
  return flag;
}

void change(int cnt, string x)
{
  if (check(x)) {
    cout << cnt << endl;
    cout << saves[0];
    for (int i = 1; i <= cnt; ++i) {
      cout << "--->" << saves[i];
    }
    cout << endl;
    return;
  }
  
  int newnum = stoi(x);
  reverse(x.begin(), x.end());
  newnum += stoi(x);
  string newx = to_string(newnum);
  saves[cnt+1] = newx;
  change(cnt+1, newx);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  string x;
  while (cin >> x) 
  {
    saves[0] = x;
    change(0, x);
  }

  return 0;
}
