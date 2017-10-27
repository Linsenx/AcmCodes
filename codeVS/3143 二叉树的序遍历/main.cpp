#include <bits/stdc++.h>
using namespace std;

void PreOrderTraversal(vector<int>&Tree, int i)
{
  if (i <= Tree.size() && Tree[i] != 0) {
    int left, right;
    left = Tree[i]*2 - 1;
    right = Tree[i]*2;
    cout << Tree[i] << " ";
    PreOrderTraversal(Tree, left);  //vist left child
    PreOrderTraversal(Tree, right);//vist Right child
  }
}

void InOrderTraversal(vector<int>&Tree, int i)
{
  if (i <= Tree.size() && Tree[i] != 0) {
    int left, right;
    left = Tree[i]*2 - 1;
    right = Tree[i]*2;
    InOrderTraversal(Tree, left);  //vist left child
    cout << Tree[i] << " ";
    InOrderTraversal(Tree, right);//vist Right child
  }
}

void PostOrderTraversal(vector<int>&Tree, int i)
{
  if (i <= Tree.size() && Tree[i] != 0) {
    int left, right;
    left = Tree[i]*2 - 1;
    right = Tree[i]*2;
    PostOrderTraversal(Tree, left);  //vist left child
    PostOrderTraversal(Tree, right);//vist Right child
    cout << Tree[i] << " ";
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

  PreOrderTraversal(Tree, 0); cout << endl;
  InOrderTraversal(Tree, 0); cout << endl;
  PostOrderTraversal(Tree, 0); cout << endl;

  return 0;
}

