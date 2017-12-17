#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
int isOk(int N, int a[])
{
  int i;
  for (i = 1; i < N && a[i] == a[0]; ++i);
=======
int isequal(int N, int a[])
{
  int i;
  for (i = 0; a[i] == a[0]; ++i);
>>>>>>> bf66a76c2c12419d466c103f78e2614868dab2a3
  return i == N;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
<<<<<<< HEAD

  int N;
  while (cin >> N && N != 0) {
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    int round = 0;
    int stu_give_index = 0;
    int stu_given_index = 0;

    while (!isOk(N, a) && round < 1) {
      for (stu_give_index = 0; stu_give_index < N; ++stu_give_index) {
        if (stu_give_index < N-1) {
          stu_given_index = stu_give_index + 1;
          int give_candy = a[stu_give_index] / 2;
          a[stu_give_index] -= give_candy;
          a[stu_given_index] += give_candy;
        }
      }
      for (int i = 0; i < N; ++i) {
        //if (a[i] % 2 != 0) a[i] += 1;
      }
      round++;
    }
    for (int i = 0; i < N; ++i) cout <<"cady: "<<a[i]<<endl;
    cout << round << endl;
  }



=======
  
  int N, rounds;
  while (cin >> N && N != 0) {
    int candy[N], tmp[N];
    for (int i = 0; i < N; ++i) cin >> candy[i];
    
    rounds = 0;
    while (!isequal(N, candy)) {
      for (int i = 0; i < N; ++i) tmp[i] = candy[i]/2;
      for (int j = 0; j < N; ++j) {
        if (j > 0)
          candy[j] = candy[j]/2 + tmp[j-1];
        else
          candy[j] = candy[j]/2 + tmp[N-1];
        if (candy[j] % 2 == 1) candy[j] += 1;
      }
      rounds ++;
    }
    cout << rounds << ' ' << candy[0] << endl;
  }
  
>>>>>>> bf66a76c2c12419d466c103f78e2614868dab2a3
  return 0;
}
