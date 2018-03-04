#include<stdio.h>
#include<string.h>
char a[1000100];
char b[1000100];
int num_a[1000100];
int num_b[1000100];
int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int N;
  int len_a, len_b;
  while (scanf("%d", &N) != EOF) {
    while (N--) {
      memset(num_a, 0, 1000100);
      memset(num_b, 0, 1000100);
      scanf("%s%s", &a, &b);
      len_a = strlen(a);
      len_b = strlen(b);

      int k_i, k_j;
      for (k_i = 0; k_i < len_a; ++k_i) num_a[k_i] = a[len_a-1-k_i] - '0';
      for (k_j = 0; k_j < len_b; ++k_j) num_b[k_j] = b[len_b-1-k_j] - '0';

      int k = 0;
      int jw = 0;
      int maxer = len_a >= len_b ? len_a : len_b;
      for (k = 0; k < maxer; ++k) {
        num_a[k] += num_b[k];
        if (num_a[k] > 9) {
          num_a[k] -= 10;
          num_a[k+1] ++;
        }
      }

      int len = num_a[maxer+1] != 0 ? maxer+1 : maxer;
      int i = len;
      for (i = len; num_a[i] == 0 && i > 0; --i); //注意结果为0的情况
      for (; i >=0; --i) {
        printf("%d", num_a[i]);
      }
      printf("\n");
    }
  }

  return 0;
}
