#include <bits/stdc++.h>
using namespace std;

struct student {
  char name[15];
  int usetime;
  int qnumber;
};

student stus[500];
int n, m, index;
char w[20];

int cmp(const void *a, const void *b)
{
  struct student *c = (student*)a;
  struct student *d = (student*)b;
  if (c -> qnumber != d -> qnumber) return d -> qnumber - c -> qnumber;
  else if(c -> usetime != d -> usetime) return c -> usetime - d -> usetime;
  else return c -> name - d -> name;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  scanf("%d%d", &n, &m);

  while(scanf("%s", &stus[index].name) != -1) {
    for (int i = 0; i < n; ++i) {
      int s1, s2, num;
      scanf("%s", &w);
      num = sscanf(w, "%d(%d)", &s1, &s2);

      if (s1 > 0) {
        stus[index].usetime += s1;
        stus[index].qnumber++;
        if (num == 2) {
          stus[index].usetime += m*s2;
        }
      }
    }
    index ++;
  }

  qsort(stus, index, sizeof(stus[0]), cmp);
  for(int ll = 0; ll < index; ++ll) {
    printf("%-10s %2d %4d\n",stus[ll].name,stus[ll].qnumber,stus[ll].usetime);
  }

  return 0;
}
