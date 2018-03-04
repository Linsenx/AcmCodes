#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+100;
int ch[maxn][10];
int val[maxn];
int sz;
char str[15];

void init()
{
  sz = 0; //将节点数初始化为0
  memset(ch[0], 0, sizeof(ch[0])); //节点数组初始化
}


bool insert(char *s)
{
  int len = strlen(s);
  int u = 0;
  int k, i;
  for(i = 0; i < len; ++i) {
    k = s[i] - '0';
    
    if(!ch[u][k]) { //第u个节点不存在k子节点，就插入u+1节点，并将u节点的k子节点指向u+1节点
      ch[u][k] = ++sz; //将u节点的k子节点指向u+1节点
      val[sz] = 0; 
      memset(ch[sz], 0, sizeof(ch[sz]));
    }
      
    u = ch[u][k];
    if(val[u]) return false; //s的前缀已经插入字符树
    else if(i == len - 1) {  //s是已经插入过的字符串的前缀
      for(int j = 0; j <= 9; ++j) { 
        if(ch[u][j])  //判断字符串s末尾的下一个节点是否有字符，有字符就构成前缀的定义
          return false;
      }
    }
  }
  val[u] = 1;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int t, n;
  scanf("%d", &t);
  while(t--) {
    init();
    bool isok = true;
    scanf("%d", &n);
    while(n--) {
      scanf("%s", str);
      if(!insert(str)) {
        isok = false;
        break;
      }
    }
    if(n > 1) while(n--) scanf("%s", str);
    isok == false ? printf("NO\n") : printf("YES\n") ;
  }

  return 0;
}
