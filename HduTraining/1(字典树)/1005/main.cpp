#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int ch[maxn][27];
int sz;
int res;
char str[55];

void init()
{
  res = 0;
  sz = 0;
  memset(ch[0], 0, sizeof(ch[0]));
}

void insert(char *s)
{
  int k, i, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; ++i)
  {
    k = s[i] - 'a';
    if(!ch[u][k]) {
      ch[u][k] = ++sz;
      memset(ch[sz], 0, sizeof(ch[sz]));
      res++;
    }
    u = ch[u][k];
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int n;
  while(~scanf("%d", &n)) {
    init();
    int maxlen = 0;
    for(int i = 0; i < n; ++i) {
      scanf("%s", str);
      insert(str);
      maxlen = maxlen >= strlen(str) ? maxlen : strlen(str);
    }
    res = 2*res + n - maxlen;
    printf("%d\n", res);
  }
  


  return 0;
}
