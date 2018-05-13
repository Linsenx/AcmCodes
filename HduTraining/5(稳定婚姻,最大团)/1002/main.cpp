#include <bits/stdc++.h>
using namespace std;

const int maxn = 200+10;
int t, c;

struct node 
{
  int id;
  int cap;
  int match;
  double x, y, z;
};
node sender[maxn];
node receiver[maxn];

double dis(node a, node b)
{
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
}

bool isAbetterthanB(node a, node b, node c)
{
  double dis_ac = dis(a, c);
  double dis_bc = dis(b, c);
  if (dis_ac == dis_bc) return a.cap > b.cap;
  else return dis_ac < dis_bc;
}

void doit()
{
  //接收点(男)主动找最近的发射点(女)
  queue<int> single; //还没有匹配的接收点(单身)
  bool rejected[maxn][maxn]; //i接收点(男)是否被j发射点(女)拒绝过
  memset(rejected, false, sizeof(rejected));
  
  //将全部接收点加入单身队列
  for (int i = 0; i < c; ++i) 
  {
    single.push(i);
    sender[i].match = -1;
  }
  
  while (!single.empty()) 
  {
    int man = single.front(); single.pop();
    int woman = -1;
    for (int i = 0; i < c; ++i) 
    {
      if (!rejected[man][i] && (woman == -1 || dis(receiver[man], sender[i]) < dis(receiver[man], sender[woman]))) woman = i;
    }
        
    int oldbf = sender[woman].match;
        
    if (oldbf == -1)
    {
      sender[woman].match = man;
    }
    else 
    {
      if (isAbetterthanB(receiver[man], receiver[oldbf], sender[woman]) == false)
      {
        //现在的男友更好 被拒绝
        rejected[man][woman] = true;
        single.push(man);
      }
      else
      {
        //甩掉旧男友
        sender[woman].match = man;
        //旧男友单身
        single.push(oldbf);
        //rejected[oldbf][woman] = true;
      }
    }
  }
  
  for (int i = 0; i < c; ++i) 
  {
    cout << sender[i].id << " " << receiver[sender[i].match].id << endl;
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
    cin >> c;
    for (int i = 0; i < c; ++i) {
      cin >> sender[i].id >> sender[i].cap >> sender[i].x >> sender[i].y >> sender[i].z;
    }
    for (int i = 0; i < c; ++i) {
      receiver[i].id = i + 1;
      cin >> sender[i].id >> receiver[i].cap >> receiver[i].x >> receiver[i].y >> receiver[i].z;
    }
    
    doit();
    
    cout << endl;
  }

  return 0;
}
