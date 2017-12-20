#include <bits/stdc++.h>
using namespace std;

int T, N;
int m[200][200];
int MM;

void findi(int x, int y)
{
  //0 1 0 1 0 1
  //1 0 1 0 1 0
  int i, j;
  int old_y = 1;
  int min_y = 100000000;
  int m_x = 0;
  for (i = x; i < N; ++i) {
    if (m[i][y] != m[i+1][y]) {
      m_x ++;
      int loc_y = 0;
      for (j = y; j < N; ++j) {
        if (m[i][j] != m[i][j+1]) {
          loc_y ++;
        } else {
          break;
        }
      }
      printf("(%d,%d) %d,%d\n",i,y,m_x,min_y );
      min_y = min(min_y, loc_y);
      MM = max(MM, m_x*min_y);
    } else {
      break;
    }
  }

  //printf("(%d,%d) => [%d, %d]\n", x, y, m_x, min_y);
  //MM = max(MM, m_x*m_y);
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  cin >> T;
  while (T--) {
    cin >> N;
    MM = 0;
    memset(m, -1, sizeof(m));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        cin >> m[i][j];

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        findi(i, j);
    cout << MM <<endl;
  }

  return 0;
}

