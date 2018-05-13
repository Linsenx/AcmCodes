#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 1000;
int T, N, M, r[maxn], m[maxn], k[maxn], f[maxn][maxn], R[maxn], C[maxn];

bool rank_aBetter(int a, int b, int FDU)
{
  if (r[a] == R[FDU])
  {
    if (r[b] == R[FDU]) {
      return m[a] > m[b];
    } else {
      return m[a] * 10 > m[b] * 7;
    }
  }
  else if (r[b] == R[FDU]) 
  {
    
    if (r[a] == R[FDU]) {
      return m[a] > m[b];
    } else {
      return m[a] * 7 > m[b] * 10;
    }
  }
  else {
    return m[a] > m[b];
  }
}

void build()
{
  vector<vector<int> > ac_student(M, vector<int>(0,0)); //大学接收的学生
  vector<int> pt_student(N, 0);
  vector<int> fdu_student(N, -1);
    
  queue<int> sg; //single
  for (int i = 0; i < N; ++i) sg.push(i);
  
  while (!sg.empty()) {
    int student = sg.front(); sg.pop();
    int FDU = f[student][pt_student[student]++];
    
    //没招满，直接招收
    if (ac_student[FDU].size() < C[FDU]) {
      ac_student[FDU].push_back(student);
      fdu_student[student] = FDU;
    } else {
      //已招满，从所有学生里面挑出比student弱的学生，将其踢出，将student加入
      int drop_student = -1;
      int drop_student_idx = -1;
      int tmp = student;
      for (int i = 0; i < ac_student[FDU].size(); ++i) {
        int stu = ac_student[FDU][i];
        if (rank_aBetter(tmp, stu, FDU) == true) {
          drop_student = stu;
          drop_student_idx = i;
          tmp = stu;
        }
      }

      if (drop_student_idx == -1) {
        if (pt_student[student] < k[student]) sg.push(student);
      } else {
        //cout << FDU << ":" << drop_student << "->" << student << "->" << rank_aBetter(6, 0, FDU) <<endl;
        ac_student[FDU].erase(ac_student[FDU].begin() + drop_student_idx);
        sg.push(drop_student);
        
        fdu_student[drop_student] = -1;
        ac_student[FDU].push_back(student);
        fdu_student[student] = FDU;
      }
    }
  }
  
  for (int i = 0; i < N; ++i) {
    if (fdu_student[i] == -1) cout << "not accepted" << endl;
    else cout << fdu_student[i]+1 << endl;
  }
  
  ac_student.clear();
  pt_student.clear();
  fdu_student.clear();
  
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  cin >> T;
  while (T--) {
    memset(f, 0, sizeof(f));
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
      cin >> r[i] >> m[i] >> k[i];
      r[i] -= 1;
      for (int j = 0; j < k[i]; ++j) {
        cin >> f[i][j];
        f[i][j] -= 1;
      }
    }
    for (int i = 0; i < M; ++i) {
      cin >> R[i] >> C[i];
      R[i] -= 1;
    }
    build();
    cout << endl;
  }

  return 0;
}
