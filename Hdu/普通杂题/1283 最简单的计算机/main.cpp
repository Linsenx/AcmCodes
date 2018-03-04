#include <bits/stdc++.h>
using namespace std;

int m1, m2, r1, r2, r3;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  string cmd;
  while (cin >> m1 >> m2)
  {
    cin >> cmd;
    r1 = r2 = r3 = 0;
    for (auto c : cmd)
    {
      if (c == 'A') r1 = m1;
      else if (c == 'B') r2= m2;
      else if (c == 'C') m1 = r3;
      else if (c == 'D') m2 = r3;
      else if (c == 'E') r3 = r1 + r2;
      else if (c == 'F') r3 = r1 - r2;
    }
    cout << m1 << "," << m2 << endl;
  }

  return 0;
}
