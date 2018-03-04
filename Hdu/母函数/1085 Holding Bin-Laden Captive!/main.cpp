#include <bits/stdc++.h>
using namespace std;

int c1[10000];
int c2[10000];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int a, b, c;
  
  //(1+x^1+x^2+...+x^a)(1+x^2+x^4+...+x^2*b)(1+x^5+x^10+...+x^5*c)
  int ml;
  
  
  while(cin >> a >> b >> c && a+b+c) {
    memset(c1, 0, 10000);
    memset(c2, 0, 10000);
    ml = 1*a+2*b+5*c;
    for(int i = 0; i <= a; ++i) {
      c1[i] = 1;
      c2[i] = 0;
    }
    
    for(int i = 0; i <= a; ++i) {
      for(int j = 0; j <= 2*b; j+=2) {
        c2[i+j] += c1[i];
      }
    }
    for(int i = 0; i <= a+2*b; ++i) {
      c1[i] = c2[i];
      c2[i] = 0;
    }
    
    for(int i = 0; i <= a+2*b; ++i) {
      for(int j = 0; j <= 5*c; j+= 5) {
        c2[i+j] += c1[i];
      } 
    }
    for(int i = 0; i <= a+2*b+5*c; ++i) {
      c1[i] = c2[i];
      c2[i] = 0;
    }
    
    int i;
    for(i = 1; i <= ml; ++i) {
      if(c1[i] == 0) {
        cout << i << endl;
        break;
      }
    }
    if(i == ml+1) cout << i << endl;
  }

  return 0;
}
