#include <bits/stdc++.h>
using namespace std;

struct student 
{
  int _id;
  int _nums;
  int _time;
};

int cmp0(student a, student b)
{
  if (a._nums != b._nums) {
    return a._nums > b._nums;
  } else {
    return a._time < b._time;
  }
}

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int h, m, s;
  int N, _nums, _time;
  while (cin >> N && N != -1) {
    student stus[N];
    for (int i = 0; i < N; ++i) {
      scanf("%d%d:%d:%d", &_nums, &h, &m, &s);
      stus[i]._id = i;
      stus[i]._nums = _nums;
      stus[i]._time = h*3600 + m*60 + s;
    }
    sort(stus, stus+N, cmp0);
    
    for (int i = 0; i < N; ++i) {
      int score = 0;
      //cout << stus[i]._nums << "=>" << stus[i]._time << endl;
      if (stus[i]._nums == 5) {
        score = 100;
      } else {
        score = 100 - 
      }
      //int max_score = 100 - (5 - stus[i]._nums)
    }
  }

  return 0;
}
