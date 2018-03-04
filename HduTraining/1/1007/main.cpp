#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5;
int sz;
int val[maxn];
int ch[maxn][27];
int n;
char str[50010][70];

void insert(char *s)
{
  int i, k, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; i++)
  {
    k = s[i] - 'a';
    if(!ch[u][k])
    {
      ch[u][k] = ++sz;
    } 
    u = ch[u][k];
  }
  val[u] = 1;
}

bool query(char *s)
{
  int i, k, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; i++)
  {
    k = s[i] - 'a';
    if(!ch[u][k]) 
      return false;
    u = ch[u][k];    
    if(val[u] == 1 && i < len - 1)
    {
      int kk, uu = 0;
      for(int si = i + 1; si < len; si++)
      {
        kk = s[si] - 'a';
        if(ch[uu][kk]) uu = ch[uu][kk];
        else break;
        if(val[uu] == 1 && si == len - 1)
          return true;
      }
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while(~scanf("%s", str[++n]))
  {
    insert(str[n]);
  }

  for(int i = 0; i < n; i++)
  {
    if(query(str[i])) printf("%s\n", str[i]);
  }

  return 0;
}
