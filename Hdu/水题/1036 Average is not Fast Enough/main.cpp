#include <bits/stdc++.h>
using namespace std;

int n, num;
double dis;
char str_s[50], str_e[50];

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  scanf("%d %lf", &n, &dis);

  while (scanf("%d %s %s", &num, str_s, str_e) != EOF)
  {
    if (strcmp(str_e, "-:--:--") == 0)
    {
      printf("%3d: -\n", num);
    }
    else
    {
      int a, b, c, d, e, f;
      sscanf(str_s, "%d:%d:%d", &a, &b, &c);
      sscanf(str_e, "%d:%d:%d", &d, &e, &f);
      double res = (d*3600+e*60+f)+(a*3600+b*60+c);
      res /= dis;
      int ans = res + 0.5;
      printf("%3d:%2d:%02d min/km\n", num, ans / 60, ans % 60);
    }

  }

  return 0;
}

/*
#include<stdio.h>
#include<math.h>
#define numify '0'

char run[10];

int main()
{
    int name;
    int round;
    double dis;
    double ans;
    int time;
    int i, j;
    int judge;
    int hour, minute, second;

    scanf("%d %lf", &round, &dis);
    while(scanf("%d", &name) != EOF)
    {
        judge = 1;
        hour = second = minute = 0;
        for(i = 1; i <= round; i ++)
        {
            scanf("%s", &run);
            if(run[0] == '-')
                judge = 0;

            if(judge)
            {
                hour += run[0] - numify;
                minute += (run[2] - numify) * 10 + run[3] - numify;
                second += (run[5] - numify) * 10 + run[6] - numify ;
            }
        }

        if(judge)
        {
            time = hour * 3600 + minute * 60 + second;
            ans = floor(time / dis + 0.5);
            printf("%3d: %d:%02d min/km\n", name, (int)(ans) / 60, (int)(ans) % 60);
        }
        else
        {
            printf("%3d: -\n", name);
        }
    }
    return 0;
}
*/
