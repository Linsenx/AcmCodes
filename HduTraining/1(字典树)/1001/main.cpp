#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int ch[maxn][2];
int val[maxn];
int sz;
char str[15];
int kase;
bool isok = true;

void init() 
{
  isok = true;
  sz = 0;
  memset(ch[0], 0, sizeof(ch[0]));
}

void insert(char *s)
{
  int k, i, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; ++i) {
    k = s[i] - '0';
    if(!ch[u][k]) {
      ch[u][k] = ++sz;
      val[sz] = 0;
      memset(ch[sz], 0, sizeof(ch[sz]));
    }
    u = ch[u][k];
    if(val[u] == 1) isok = false;
    else if(i == len - 1) {
      for(int j = 0; j <= 1; ++j) {
        if(ch[u][j]) {
          isok = false;
        }
      }
    }
  }
  val[u] = 1;
}

bool query(char *s)
{
  int k, i, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; ++i) {
    k = s[i] - '0';
    if(!ch[u][k])
      return false;
    u = ch[u][k];
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  init();
  while(~scanf("%s", str)) {
    if(strlen(str) == 1 && str[0] == '9') {
      isok ? printf("Set %d is immediately decodable\n", ++kase) : printf("Set %d is not immediately decodable\n", ++kase);
      //output and init
      init();
    } else {
      if(isok == true) insert(str);
    }
  }
  
  

  return 0;
}
