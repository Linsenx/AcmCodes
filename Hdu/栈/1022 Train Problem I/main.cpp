#include <bits/stdc++.h>
using namespace std;

int N, k, tb;
string t_in, t_out;

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> N >> t_in >> t_out) {
    k = 0;
    tb = 0;
    stack<char>train;
    int flag[500];
    for (int i = 0; i < N; ++i) {
      train.push(t_in[i]);
      flag[k++] = 1;
      while (!train.empty()) {
        if (train.top() == t_out[tb]) {
          flag[k++] = 0;
          train.pop();
          tb++;
        } else {
          break;
        }
      }
    }


    if (train.empty()) {
      cout << "Yes." << endl;
      for (int i = 0; i < k; ++i) {
        if (flag[i] == 1) cout << "in" << endl;
        else cout << "out" << endl;
      }
    } else {
      cout << "No." << endl;
    }
    cout << "FINISH" << endl;
  }

  return 0;
}
