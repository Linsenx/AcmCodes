#include <bits/stdc++.h>
using namespace std;

//vector<vector<int> > tree[27];
const int MAX_INT = 1e9;
int D[27][27];

void init()
{
  //for (int i = 0; i < 27; ++i) tree[i].clear();
  
  for (int i = 0; i < 27; ++i)
    for (int j = 0; j < 27; ++j)
      D[i][j] = i == j ? 0 : MAX_INT;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  string word;
  init();
  while (cin >> word) {
    if (word == "0") {
      int N = 26;
      for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < N; ++j)
            D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      
      D['b'-'a']['m'-'a'] == 1e9 ? cout << "No." << endl : cout << "Yes." << endl;
      
      init();
    } else {
      int a = word.front() - 'a';
      int b = word.back() - 'a';
      D[a][b] = 1;
    }
  }
  
  return 0;
}
