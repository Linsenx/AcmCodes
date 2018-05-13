#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int sz;
int vis[maxn];
int val[maxn];
int ch[maxn][27];

void insert(char *s, int id)
{
  int i, k, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; ++i) {
    k = s[i] - 'a';
    if(!ch[u][k]) {
      ch[u][k] = ++sz;
      vis[ch[u][k]] = id;
      val[ch[u][k]] ++;
    }
    u = ch[u][k];
    if(vis[u] != id) {
      val[u]++;
      vis[u] = id;
    }
  }
}

int query(char *s)
{
  int i, k, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; ++i) {
    k = s[i] - 'a';
    if(!ch[u][k])
      return 0;
    u = ch[u][k];
  }
  return val[u];
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int P, Q;
  char str[30];
  scanf("%d", &P);
  while(P--) {
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; ++i) {
      insert(str + i, P);
    }
  }
  scanf("%d", &Q);
  while(Q--) {
    scanf("%s", str);
    printf("%d\n", query(str));
  }

  return 0;
}
