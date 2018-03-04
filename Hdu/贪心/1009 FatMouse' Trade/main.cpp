#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct room {
  double J;
  double F;
  double P;
};

double M, Bought;
int N;
room rooms[1005];

bool cmp(room a, room b)
{
  return a.P > b.P;
}

int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (scanf("%lf%d",&M,&N)) {
    if (M == -1 && N == -1) break;
    Bought = 0;
    for(int i = 0; i < N; ++i) {
      scanf("%lf%lf", &rooms[i].J, &rooms[i].F);
      //这个(double)巨坑
      rooms[i].P = (double)rooms[i].J/rooms[i].F; 
    }
    sort(rooms, rooms + N, cmp);
    for (int j = 0; j < N; ++j) {
      if (M >= rooms[j].F) {
        M -= rooms[j].F;
        Bought += rooms[j].J;
      } else {
        double buy_rate = M / rooms[j].F;
        Bought += rooms[j].J*buy_rate;break;
      }
    }
    printf("%.3lf\n", Bought);
  }
  return 0;
}
