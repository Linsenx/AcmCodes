#include <bits/stdc++.h>
using namespace std;

int n, cnt, mark[5010];
struct stick
{
  int l, w;
  stick(int a=0, int b=0):l(a), w(b){}
};
vector<stick> sticks;

bool cmp(stick a, stick b)
{
  if (a.l == b.l) return a.w < b.w;
  else return a.l < b.l;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int test, a, b;
  cin >> test;
  while (test--) 
  {
    cin >> n;
    sticks.clear();
    cnt = 0;
    memset(mark, -1, sizeof mark);
    for (int i = 0; i < n; ++i) 
    {
      cin >> a >> b;
      sticks.push_back(stick(a, b));
    }
    sort(sticks.begin(), sticks.end(), cmp);
    
    stick tmp;
    for (int i = 0; i < n; ++i) 
    {
      if (mark[i] == -1) 
      {
        tmp = sticks[i];
        for (int j = i + 1; j < n; ++j)
        {
          if (sticks[j].w >= tmp.w && sticks[j].l >= tmp.l && mark[j] == -1)
          {
            tmp = sticks[j];
            mark[j] = 1;
          }
        }
        cnt ++;
        mark[i] = 1;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
