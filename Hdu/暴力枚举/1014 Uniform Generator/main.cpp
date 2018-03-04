#include <bits/stdc++.h>
using namespace std;

set<int>nums;
int STEP, MOD, kase;
int seed[100010];

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  //seed(x+1) = [seed(x) + STEP] % MOD
  seed[0] = 0;
  while (~scanf("%d%d", &STEP, &MOD)) {
    nums.clear();
    for (int x = 1; x < MOD; ++x) {
      seed[x+1] = (seed[x] + STEP) % MOD;
      if (seed[x+1] >= 0 && seed[x+1] <= MOD-1) {
        nums.insert(seed[x+1]);
      }
    }
    if (nums.size() == MOD-1)
      printf("%10d%10d    %s\n\n", STEP, MOD, "Good Choice");
    else 
      printf("%10d%10d    %s\n\n", STEP, MOD, "Bad Choice");
    
    kase ++;
  }

  return 0;
}
