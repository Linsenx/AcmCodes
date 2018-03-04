#include <bits/stdc++.h>
using namespace std;

int chd[2000010][27];
int val[2000010];
int sz;

void insert(char *s)
{
  int len = strlen(s);
  int rt = 0;
  for(int i = 0; i < len; ++i) 
  {
    int k = s[i] - 'a';
    if(!chd[rt][k])
      chd[rt][k] = ++sz;
    rt = chd[rt][k];
    val[rt]++;
  }
}

int query(char *s)
{
  int len = strlen(s), rt = 0;
  for(int i = 0; i < len; ++i)
  {
    int k = s[i] - 'a';
    rt = chd[rt][k];
    if(rt == 0) return 0;
  }
  return val[rt];
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  char s1[15];  
  
  while(gets(s1)&&s1[0])  
    insert(s1);  
  
  while(gets(s1))  
    cout<<query(s1)<<endl; 

  return 0;
}
