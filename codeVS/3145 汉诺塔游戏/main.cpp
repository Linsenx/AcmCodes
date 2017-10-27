#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char A, char B, char C)
{
  if (n == 1) {
    cout << n << " from " << A << " to " << C << endl;
  } else {
    hanoi(n-1, A, C, B);
    cout << n << " from " << A << " to " << C << endl;
    hanoi(n-1, B, A, C);
  }
}


int main()
{
  ios::sync_with_stdio(false);
  freopen("in.txt", "r", stdin);

  int x = 0, steps = 0;
  cin >> x;
  cout << pow(2,x)-1 << endl;
  hanoi(x, 'A', 'B', 'C');
  return 0;
}
