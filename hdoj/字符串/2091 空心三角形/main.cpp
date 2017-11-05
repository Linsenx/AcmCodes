#include <bits/stdc++.h>
using namespace std;

int h;
char fill_;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  int jjj = 0;
  while(cin >> fill_ && fill_ != '@') {
    cin >> h;
    if (jjj > 0) cout << endl;
    for (int i = 0; i < h; ++i) {
      if (i != h-1) {
        int white_num = h-i-1;
        for (int j = 0; j < white_num; ++j) cout << ' ';
        cout<< fill_;
        white_num = 2*i-1;
        for (int j = 0; j < white_num; ++j) cout << ' ';
        if (i != 0) cout<< fill_;
      } else {
        for (int i = 0; i < h*2-1 ; ++i) cout << fill_;
      }
      cout << endl;
    }
    jjj++;
  }

  return 0;
}
