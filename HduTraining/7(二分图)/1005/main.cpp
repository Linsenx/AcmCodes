#include <bits/stdc++.h>
using namespace std;

int k, mp[30][30], vis[30], match[30];
string cards_adam[30], cards_eve[30];

map<char, int> rank_value;


bool compare(string a, string b)
{
  if (a[0] != b[0]) {
    return rank_value[a[0]] > rank_value[b[0]];
  } else {
    if (a[1] == 'H' && b[1] != 'H') return true;
    else if (a[1] == 'S' && b[1] != 'H') return true;
    else if (a[1] == 'D' && b[1] == 'C') return true;
    else return false;
  }
  return false;
}

bool dfs(int x)
{
  for (int j = 0; j < k; ++j) {
    if (mp[x][j] == 1 && !vis[j]) {
      vis[j] = 1;
      if (match[j] == -1 || dfs(match[j])) {
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

void Hungary()
{
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    memset(vis, 0, sizeof vis);
    if (dfs(i)) ans ++;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  rank_value['A'] = 13;
  rank_value['K'] = 12;
  rank_value['Q'] = 11;
  rank_value['J'] = 10;
  rank_value['T'] = 9;
  rank_value['9'] = 8;
  rank_value['8'] = 7;
  rank_value['7'] = 6;
  rank_value['6'] = 5;
  rank_value['5'] = 4;
  rank_value['4'] = 3;
  rank_value['3'] = 2;
  rank_value['2'] = 1;
  
  int test;
  string str;
  cin >> test;
  while (test--) {
    memset(mp, 0, sizeof mp);
    memset(match, -1, sizeof match);
    cin >> k;
    for (int i = 0; i < k; ++i) cin >> cards_adam[i];
    for (int i = 0; i < k; ++i) cin >> cards_eve[i];
    
    for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j) {
      if (compare(cards_eve[i], cards_adam[j])) {
        mp[i][j] = 1;
      }
    }
    Hungary();
  }

  return 0;
}
