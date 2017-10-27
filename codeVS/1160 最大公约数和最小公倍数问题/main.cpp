#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  int map[n][n];
  memset(map, 0, sizeof(map));
  int centerx, x;
  int centery, y;
  centerx = centery = x = y = (n-1)/2;
  int round = 1;
  int fx[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
  int fx_flag = 0;
  for (int i = 0; i < n*n; ++i) {

    map[x][y] = i+1;
    if ( x == y && x == n-1) {
      break;
    }

    if (x + fx[fx_flag][0] > centerx + round ||  x + fx[fx_flag][0] < centerx - round
     || y + fx[fx_flag][1] > centery + round ||  y + fx[fx_flag][1] < centery - round
      ) {
      fx_flag = fx_flag == 3 ? 0 : fx_flag + 1;
    }
    x += fx[fx_flag][0];
    y += fx[fx_flag][1];

    if (x == centerx + round && y == centery + round){


      round ++;
    }
  }

  int duijiao = 0;
  for(int j = 0; j < n; ++j) {
    for(int k = 0; k < n; ++k) {
        if (j == k || j+k == n-1) {
            duijiao += map[j][k];
        }
      cout << map[j][k] << " ";
    }
    cout << endl;
  }
  cout << duijiao << endl;

  return 0;
}
