#include <bits/stdc++.h>
using namespace std;

const int N = 500;

char name[N];
int t, n, cnt, id[N], husband[N], ranked[N][N];

char readc()
{
  char c;
  cin >> c;
  return c;
}

int getrank(int woman, int man)
{
  for (int i = 0; i < n; ++i) {
    if (ranked[woman][i] == man) return i;
  }
  return n;
}

int getwife(int man)
{
  for (int i = n+1; i <= 2*n; ++i) {
    if (husband[i] == man) return i;
  }
  return 0;
}

void build()
{
  int pt[N];
  memset(pt, 0, sizeof pt);
  memset(husband, -1, sizeof husband);
  
  queue<int> single;
  for (int i = 1; i <= n; ++i) single.push(i);
  
  while (!single.empty()) {
    int man = single.front(); single.pop();
    int woman = ranked[man][pt[man]++];
    
    int old_husband = husband[woman];
    if (old_husband == -1) {
      husband[woman] = man;
    } else {
      if (getrank(woman, man) < getrank(woman, old_husband)) {
        single.push(old_husband);
        husband[woman] = man;
      } else {
        single.push(man);
      }
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
  
  cin >> t;
  while (t--) {
    cin >> n;
    cnt = 0;
    char c;
    for (int i = 0; i < n*2; ++i) {
      c = readc();
      id[c] = ++cnt;
      name[id[c]] = c;
    }
      
    for (int i = 0; i < n*2; ++i) {
      int obj = readc(); readc();
      for (int j = 0; j < n; ++j)
        ranked[id[obj]][j] = id[readc()];
    }
    
    build();
    
    for (int i = 1; i <= n; ++i) {
      cout << name[i] << " " << name[getwife(i)] << endl;
    }
    if (t != 0) cout << endl;
  }

  return 0;
}
