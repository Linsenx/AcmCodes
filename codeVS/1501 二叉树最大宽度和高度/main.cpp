#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>&Tree, int i, int Height, int &MaxHeight, vector<int>&Width)
{
  if (i <= Tree.size() && Tree[i] != 0) {
    Width[Height] ++;
    MaxHeight = max(Height, MaxHeight);
    int left, right;
    left = Tree[i]*2 - 1;
    right = Tree[i]*2;
    dfs(Tree, left, Height + 1, MaxHeight, Width);  //vist left child
    dfs(Tree, right, Height + 1, MaxHeight, Width);//vist Right child
  }
}

int cmp1(int a,int b)
{
    return b < a;
}

int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int N = 0, MaxHeight = 0;
  cin >> N;
  vector<int> Width(N+1, 0);
  vector<int> Tree(2*N+1, 1);
  for(int i = 1; i < Tree.size(); ++i)
    cin >> Tree[i];

  dfs(Tree, 0, 1, MaxHeight, Width);
  sort(Width.begin(), Width.end(), cmp1);
  cout << Width[0] << ' ' << MaxHeight << endl;

  return 0;
}

