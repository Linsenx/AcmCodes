#include<iostream>
#include<string.h>
#include <math.h>
//#include<string>
//#include<vector>
//#include<stack>
using namespace std;

int n, k, width_all;
char block[1000][1000];
char pic[1100][1100];
void draw(int deep, int x, int y)
{
  int i, j, nx, ny;
  if (deep == 1) {
    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        nx = x+i;
        ny = y+j;
        //if (block[i][j] != ' ') {
          pic[nx][ny] = block[i][j];
        //}
      }
    }
    return;
  }


  int T = n*n;
  int block_width = sqrt(pow(T, deep-1));
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (block[i][j] == '*') {
        nx = x + (block_width)*i;
        ny = y + (block_width)*j;
        draw(deep-1, nx, ny);
      }
    }
  }
}

int main()
{
//  ios::sync_with_stdio(false);
//  freopen("in.txt","r",stdin);

  int i, j, len;
  string line;
  while (cin >> n >> k) {
    //memset(pic, '\0', sizeof(pic));
    getchar();
    for (i = 0; i < n; ++i) {
      getline(cin, line);
      len = line.size();
      for (j = 0; j < len; ++j) {
        block[i][j] = line[j];
      }
    }
    draw(k,0,0);
    width_all = sqrt(pow(n*n, k));
    int i, j;
    for (i = 0; i < width_all; ++i) {
      for (j = 0; j < width_all; ++j) {
        if (pic[i][j] == '*') {
          cout << pic[i][j];
        } else {
          cout << ' ';
        }
        pic[i][j] = ' ';
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
