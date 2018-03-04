#include <bits/stdc++.h>
using namespace std;

int N, M, mt = 99999999;
char maps[110][110];

string m[500];
string msg[500][500];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x, int y, int t)
{
  if (x == 0 && y == 0 && maps[0][0] >= '1' && maps[0][0] <= '9') {
    t += (int)(maps[0][0] - '0');
  }

  if (x == N-1 && y == M-1) {
    mt = min(mt, t);
    return;
  }

  int nx, ny;
  for (int i = 0; i < 4; ++i) {
    nx = x + dir[i][0];
    ny = y + dir[i][1];
    if (nx >= 0 && nx < N && ny >=0 && ny < M) {
      if (maps[nx][ny] == 'X') continue;

      string loc_m = "("+to_string(x)+","+to_string(y)+")->("+to_string(nx)+","+to_string(ny)+")";
      m[t] = loc_m;

      if (maps[nx][ny] >= '1' && maps[nx][ny] <= '9') {
          char loc = maps[nx][ny];
          int cost = (int)(loc - '0');
          maps[nx][ny] = 'X';
          dfs(nx, ny, t+1+cost);
          maps[nx][ny] = loc;
      } else if (maps[nx][ny] == '.') {
          maps[nx][ny] = 'X';
          dfs(nx, ny, t+1);
          maps[nx][ny] = '.';
      }
    }
  }

}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> N >> M) {
    mt = 99999999;

    for (int i = 0; i < N; ++i)
      cin >> maps[i];

    dfs(0,0,0);

    if (mt != 99999999) {
      for (int j = 0; j < mt; ++j) {
        cout << m[j] << endl;
      }
    }
    //cout << mt << endl;
   }







  return 0;
}
