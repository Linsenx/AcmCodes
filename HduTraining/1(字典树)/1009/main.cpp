#include <bits/stdc++.h>
using namespace std;

//struct node
//{
//  char str[120];
//  int rate;
//};

const int maxn = 1e6;
int sz;
int val[maxn];
int ch[maxn][27];

int m[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4}; //表示按键i有几个字符 
char chh[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

string temp;
int maxrate = 0;

void init()
{
  sz = 0;
  val[0] = 0;
  memset(ch[0], 0, sizeof(ch[0]));
}

//int chg(char s)
//{
//  if(s >= 'a' && s <= 'c') return 2-2;
//  else if(s >= 'd' && s <= 'f') return 3-2;
//  else if(s >= 'g' && s <= 'i') return 4-2;
//  else if(s >= 'j' && s <= 'l') return 5-2;
//  else if(s >= 'm' && s <= 'o') return 6-2;
//  else if(s >= 'p' && s <= 's') return 7-2;
//  else if(s >= 't' && s <= 'v') return 8-2;
//  else if(s >= 'w' && s <= 'z') return 9-2;
//}

void dfs(int now, int len, int u, char *input, string s)
{
  if(now == len) {
    if(val[u] > maxrate) {
      maxrate = val[u];
      temp = s;
      return;
    }
  }
  int k = input[now] - '0';
  for(int i = 0; i < m[k]; ++i) {
    if(ch[u][chh[k][i] - 'a']) {
      dfs(now + 1, len, ch[u][chh[k][i] - 'a'], input, s+chh[k][i]);
    }
  }
}

void insert(char *s, int rate)
{
  int i, k, u = 0;
  int len = strlen(s);
  for(i = 0; i < len; ++i) {
    k = s[i] - 'a';
    if(!ch[u][k]) {
      ch[u][k] = ++sz;
      val[sz] = 0;
      memset(ch[sz], 0, sizeof(ch[sz]));
    }
    u = ch[u][k];
    val[u] += rate;
  }
}



int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int t, kase = 0;
  scanf("%d", &t);
  while(t--) {
    init();
    int n, q;
    scanf("%d", &n);
    while(n--) {
      int rate;
      char str[120];
      scanf("%s %d", str, &rate);
      insert(str, rate);
    }
    scanf("%d", &q);
    printf("Scenario #%d:\n", ++kase);
    while(q--) {
      char str[120];
      scanf("%s", str);
      int len = strlen(str);
      for(int i = 0; i < len - 1; ++i) {
        maxrate = 0;
        dfs(0, i + 1, 0, str, "\0");
        if(maxrate > 0) cout << temp << endl;
        else cout << "MANUALLY" << endl;
        //query(str, i + 1);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
