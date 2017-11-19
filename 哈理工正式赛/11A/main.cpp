#include<iostream>
#include<string.h>
#include<map>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int N;

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  int i;
  char cmd;
  string phonenumber;
  char doit;
  while (cin >> N) {
    map<string, int>q;
    map<string, int>s;
    map<string, int>k;
    // q >> s >> k
    for (i = 0; i < N; ++i) {
      cin >> cmd;
      cin >> phonenumber;
      if (cmd == 'A') {
        int qq, ss, kk, t_max;
        t_max = 0;
        qq = q[phonenumber];
        ss = s[phonenumber];
        kk = k[phonenumber];
        t_max = max(max(qq, ss), kk);

        if (t_max == 0) {
          cout << 'N' << endl;
          continue;
        }

        if (t_max == qq) {
          cout << "q=" << qq << endl;
        } else if (t_max == ss) {
          cout << "s=" << ss << endl;
        } else if (t_max == kk) {
          cout << "k=" << kk << endl;
        }
      } else if (cmd == 'B') {
        cin >> doit;
        if (doit == 'k') {
          k[phonenumber] ++;
        } else if (doit == 's') {
          s[phonenumber] ++;
        } else if (doit == 'q') {
          q[phonenumber] ++;
        }
        cout << 'Y' << endl;
      }
    }
  }

  return 0;
}
