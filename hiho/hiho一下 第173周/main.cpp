#include <bits/stdc++.h>
using namespace std;

int A[1005];
int memo[1005][1005];

int sum(int i, int j)
{
  int sums = 0;
  for(int m = i; m <= j; ++m)
    sums += A[m];
  return sums;
}

int solve(int i, int j)
{
  //1.������������ȡ��һ����A[i],���ֵ����÷�Ϊsolve(i+1, j),�Լ�������Ϊsum(i,j)-solve(i+1, j)
  //1.������������ȡ���һ����A[j],���ֵ����÷�Ϊsolve(i, j-1),�Լ�������Ϊsum(i,j)-solve(i, j-1)
  // i . ... j
  //-1 0 100 2
  if (memo[i][j] != -1) return memo[i][j];
  if (max(i,j)-min(i,j)==1) return max(A[i],A[j]);
  int max_st = max(sum(i,j)-solve(i+1, j), sum(i,j)-solve(i, j-1));
  memo[i][j] = max_st;
  return max_st;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int n;
  cin >> n;
  memset(memo, -1, sizeof(memo));
  for(int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  cout << solve(0,n-1);
  return 0;
}
