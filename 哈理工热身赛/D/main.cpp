#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;

int N, x, minjump=9999999;
int nums[30100];

void jump(int x, int nowjump) {
  if (x == N)
  {
    minjump = min(minjump, nowjump);
    return;
  }
  else if (nums[x] >= N-x)
  {
    minjump = min(minjump, nowjump+1);
    return;
  }
  else if (x > N)
  {

    return;
  }
  int i;
  int maxjump = nums[x];
  int localmax = 0;
  int indexm = 0;
  for (i = 0; i < maxjump && x+i < N; ++i) {
    if ((x+i+1) + nums[x+i+1] >= x+nums[x] && ((x+i+1) + nums[x+i+1]) > localmax) {
      localmax = (x+i+1) + nums[x+i+1];
      indexm = x+i+1;
    }
  }
  jump(indexm, nowjump+1);
}


int main()
{
//  ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);

  int i;
  while (scanf("%d", &N) != EOF) {
    minjump=9999999;
    memset(nums,0,30100);
    for (i = 1; i <= N; ++i) {
      scanf("%d", &nums[i]);
    }
    jump(1,0);
    printf("%d\n", minjump);
  }

  return 0;
}
