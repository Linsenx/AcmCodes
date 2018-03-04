#include <bits/stdc++.h>
using namespace std;

#define cout_all(v) for(auto x:v) cout << x << endl

const int N = 500 + 10;
int n, id;
vector<int>man;
vector<int>woman;
map<string,int>p_man;
map<string,int>p_woman;
map<int,string>names;
int G_man[N][N];
int G_woman[N][N];
int rank_man[N][N]; //rank_man[i][j] 男生i第j喜欢的女生id
int rank_woman[N][N];
int husband[N];

void build()
{

  int man_pointer[N*2];
  memset(husband, -1, sizeof(husband));
  memset(man_pointer, 0, sizeof(man_pointer));
  
  queue<int> single;
  for (auto x:man) single.push(x);

  while (!single.empty())
  {
    int man = single.front(); single.pop();
    int woman = rank_man[man][man_pointer[man]++];
    
    //没结婚
    if (husband[woman] == -1)
    {
      //结婚，脱单
      husband[woman] = man;
    }
    else 
    {
      int old_husband = husband[woman];
      //如果更喜欢新男友，抛弃旧男友
      if (G_woman[woman][man] < G_woman[woman][old_husband])
      {
        single.push(old_husband);
        //找新男友结婚
        husband[woman] = man;
      }
      else
      {
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
  
  string name;
  int obj_id;
  while (cin >> n)
  {
    id = 0;
    p_man.clear();
    p_woman.clear();
    man.clear();
    woman.clear();
    names.clear();
    //man
    for (int i = 0;i < n;++i) 
    {
      cin >> name;
      p_man[name] = ++id;
      names[p_man[name]] = name;
      obj_id = p_man[name];
      man.push_back(p_man[name]);
      for (int j = 0;j < n;++j) 
      {
        cin >> name;
        if (p_woman[name] == 0) p_woman[name] = ++id, woman.push_back(p_woman[name]);
        names[p_woman[name]] = name;
        G_man[obj_id][p_woman[name]] = j;
        rank_man[obj_id][j] = p_woman[name];
      }
    }
      
    //woman
    for (int i = 0;i < n;++i)
    {
      cin >> name;
      obj_id = p_woman[name];
      for (int j = 0;j < n;++j)
      {
        cin >> name;
        G_woman[obj_id][p_man[name]] = j;
        rank_woman[obj_id][j] = p_man[name];
      }
    }
    
    build();
    
    for (auto __:woman)
    {
      cout << names[husband[__]] << " " << names[__] << endl;
    }
    cout << endl;
  }


  return 0;
}
