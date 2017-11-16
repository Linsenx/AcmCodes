#include <bits/stdc++.h>
using namespace std;

int main()
{
  //ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  char word[90];
  int first = false;
  int numcount = 0;
  
  while (scanf("%s", &word) != EOF) {
    if (!strcmp("<br>", word)) {
      numcount = 0;
      printf("\n");
    } else if (!strcmp("<hr>", word)) {
      if (numcount)
        printf("\n");
      printf("--------------------------------------------------------------------------------");
      printf("\n");
      numcount = 0;
    } else {
      if (numcount + strlen(word) + 1 <= 80) {
        if (numcount)
          printf(" ");
        printf("%s", word);
        numcount += strlen(word) + 1;
      } else {
        printf("\n");
        printf("%s", word);
        numcount = strlen(word);
      }
    }
  }
  printf("\n");

  return 0;
}
