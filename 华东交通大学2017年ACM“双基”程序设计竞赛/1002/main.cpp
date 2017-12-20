#include <bits/stdc++.h>
using namespace std;

int T, n, q, st1, st2;
int boy[200100];

int main()
{
  /*ios::sync_with_stdio(false);*/
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  while (scanf("%d", &T) != EOF) {
    while (T--) {
      st1 = 0;
      st2 = 1;
      scanf("%d%d", &n, &q);
      while (q--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) {
          //移动
          int step, next;
          cin >> step;
          st1 = (st1+step+n) % n;
          st2 = (st2+step+n) % n;
        } else {
          //交换
          if (st1 % 2 == 1) {
            st1--;
            st2++;
          } else {
            st1++;
            st2--;
          }
        }
        //cout << st1 << endl;
      }
      
      //奇数变化和1一样
      int change1 = st1 - 0;
      for (int i = 0; i <= n - 2; i += 2)
      {
        int next = (i+change1+n) % n;
        boy[next] = (i+1);
      }
        
      //偶数变化和2一样
      int change2 = st2 - 1;
      for (int i = 1; i <= n - 1; i += 2)
      {
        int next = (i+change2+n) % n;
        boy[next] = (i+1);
      }
        
      printf("%d", boy[0]);
      for (int i = 1; i < n; ++i) printf(" %d", boy[i]);
      printf("\n");
    }
  }

  return 0;
}
