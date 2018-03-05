#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1<<15], ttime[1<<15], path[1<<15];
const int inf = 1e9;
struct subject
{
  string name;
  int dline, cost;
} subjects[20];

void outpath(int status)
{
  /*if (status == 0) return;
  outpath(status - (1<<path[status]));
  cout << subjects[path[status]].name << endl;*/
  if (status == 0) return;
  outpath(path[status]);
  for (int i = 0; i < n; ++i) {
    if ((status >> i & 1) && !(path[status] >> i & 1)) {
      cout << subjects[i].name << endl;
      break;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0;i < n;++i)
    {
      cin >>  subjects[i].name >> subjects[i].dline >> subjects[i].cost;
    }
    memset(path, 0, sizeof path);
    memset(ttime, 0, sizeof ttime);
    for (int i = 1;i < (1<<n);++i)
    {
      dp[i] = inf;
      for (int j = n; j >= 0; j--)
      {
        if (!(i>>j&1)) continue;
        int del = 1 << j;
        int reduce = ttime[i - del] + subjects[j].cost - subjects[j].dline;
        if (reduce < 0) reduce = 0;
        //cout <<i <<":"<<ttime[i - del] << "---->" << subjects[j].dline << endl;
        if (dp[i] > dp[i-del] + reduce)
        {
          dp[i] = dp[i-del] + reduce;
          ttime[i] = ttime[i - del] + subjects[j].cost;
          //path[i] = j;
          path[i] = i-del;
        }
      }
    }
    cout << dp[(1<<n)-1] << endl;
    outpath((1<<n)-1);
  }

  return 0;
}
