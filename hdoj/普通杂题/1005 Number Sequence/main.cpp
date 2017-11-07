/*#include <bits/stdc++.h>
using namespace std;

int T[7] = {16, 6, 24, 48, 21, 6, 2};
int fib[200];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int A, B;
  A = 1;
  B = 4;
  fib[1] = fib[2] = 1;
  cout << 1 << ':' << fib[1] << endl;
  cout << 2 << ':' << fib[2] << endl;
  for (int i = 3; i < 200; ++i) {
    fib[i] = (A*fib[i-1] + B*fib[i-2]) % 7;
    cout << i << ':' << fib[i] << endl;
  }

  int A, B, n, kase, t;
  fib[1] = fib[2] = 1;
  while (cin >> A >> B >> n && A !=0 && B != 0 && n != 0) {
    kase = B % 7;
    t = T[kase];
    for (int i = 3; i <= t; ++i)
      fib[i] = (A*fib[i-1] + B*fib[i-2]) % 7;
    kase = n % t;
    cout << t << endl;
  }

  return 0;
}*/


#include<stdio.h>
int main()
{
    int a,b,n,i,arr[48];
    while(scanf("%d %d %d",&a,&b,&n),a||b||n){
        arr[1]=1;
        arr[2]=1;
        for(i=3;i<48;i++)
            arr[i]=((a*arr[i-1]+b*arr[i-2])%7);
        printf("%d\n",arr[n%48]);
    }
    return 0;
}
