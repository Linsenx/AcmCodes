#include <iostream>
using namespace std;

//struct node 
//{
//  int cnt;        //字符出现的次数
//  node *next[27]; //节点指针
//  node() {
//    cnt = 0;
//    memset(next, NULL, sizeof(next));
//  }
//};
//
//void insert(node *p, char *s) 
//{
//  int i = 0;
//  while(s[i])
//  {
//    int k = s[i] - 'a';
//    if(!p->next[k])
//      p->next[k] = new node();
//    p = p->next[k];
//    i++;
//    p->cnt++;
//  }
//}
//
//int query(node *p, char *s)
//{
//  int i = 0;
//  while(s[i])
//  {
//    int k = s[i] - 'a';
//    if(!p->next[k])
//      return 0;
//    p = p->next[k];
//    i++;
//  }
//  return p->cnt;
//}


int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
//  char s1[15];  
//  node *p=new node();  
//  
//  while(gets(s1)&&s1[0])  
//    insert(p,s1);  
//  
//  while(gets(s1))  
//    cout<<query(p,s1)<<endl; 

  return 0;
}
