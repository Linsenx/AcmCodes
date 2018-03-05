#include <bits/stdc++.h>
using namespace std;

int n, vis[20], mark[20], max_, max_id, _indx;
struct suject
{
  string name;
  int dline;
  int cost;
} subjects[20];
vector< vector<int> > path;

void dfs(int cnt, int day, int score_reduce)
{
  if (score_reduce > max_)
  {
    return;
  }
  if (cnt >= n)
  {
    vector<int>tmp;
    for (int i = 0; i < n; ++i) tmp.push_back(mark[i]);
    path.push_back(tmp);
    if (score_reduce < max_) max_ = score_reduce, max_id = _indx;
    _indx ++;
    return;
  }
  for (int i = 0; i < n; ++i)
  {
    if (!vis[i])
    {
      vis[i] = 1;
      mark[cnt] = i;
      int reduce = day+subjects[i].cost > subjects[i].dline ? day+subjects[i].cost - subjects[i].dline: 0;
      dfs(cnt+1, day+subjects[i].cost, score_reduce+reduce);
      vis[i] = 0;
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
    _indx = 0;
    path.clear();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
      cin >>  subjects[i].name >> subjects[i].dline >> subjects[i].cost;
    }
    max_ = 1e9;
    dfs(0,0,0);
    cout << max_ << endl;
    for (auto x : path[max_id])
    {
      cout << subjects[x].name << endl;
    }
  }

  return 0;
}
