#include <bits/stdc++.h>
using namespace std;

bool comp(const char& a,const char& b){  
  return a>b;  
}  

int main()
{
//  ios::sync_with_stdio(false);
//  cin.tie(0);
  
  int target, len, v, w, x, y, z;
  char s[55];

  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> target >> s) {
    if (target == 0 && !strcmp(s,"END")) {
      break;
    }
    
    int sol = 0;
    len = strlen(s);
    sort(s, s + len);
    
    for (int a = len-1; a >= 0 && !sol; --a) {
      for (int b = len-1; b >= 0 && !sol; --b) {
        if (b == a)
          continue;
        for (int c = len-1; c >= 0 && !sol; --c) {
            if (c == a || c == b)
              continue;
          for (int d = len-1; d >= 0 && !sol; --d) {
              if (d == a || d == b || d == c)
                continue;
            for (int e = len-1; e >= 0 && !sol; --e) {
              if (e == a || e == b || e == c || e == d)
                continue;
              v = s[a]-'A'+1;
              w = s[b]-'A'+1;
              x = s[c]-'A'+1;
              y = s[d]-'A'+1;
              z = s[e]-'A'+1;
              if (v - w*w + x*x*x - y*y*y*y + z*z*z*z*z == target) {
                sol = 1;
                cout << s[a] << s[b] << s[c] << s[d] << s[e] << endl; 
              }
            }
          }
        }
      }
    }
    
    if (sol == 0) {
       printf("no solution\n"); 
    }
    
  }

  return 0;
}