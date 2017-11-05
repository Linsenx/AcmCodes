#include <bits/stdc++.h>
using namespace std;

const double esp = 1e-4;

struct p {
  double x;
  double y;
} points[305];

double getdis(p a, p b)
{
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

p getcp(p a, p b, int dd)
{
  double dis = getdis(a, b);
  double h = sqrt(1 - (dis/2)*(dis/2));
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double theta = atan(- dx / dy);
  double centerx = (a.x + b.x)/2;
  double centery = (a.y + b.y)/2;
  p cp;
  cp.x = centerx + cos(theta) * h * dd;
  cp.y = centery + sin(theta) * h * dd;
  return cp;
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
  
  int T, N;
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> points[i].x >> points[i].y;
    
    int max_cnt = 1;
    for (int m = 0; m < N; ++m) {
      for (int n = m + 1; n < N; ++n) {
        double dis = getdis(points[m], points[n]);
        if (dis >= 2 + esp + esp) continue;
        p cp = getcp(points[m], points[n], 1);
        int cnt = 0;
        for (int o = 0; o < N; ++o) {
          double pdis = getdis(cp, points[o]);
          if (pdis <= 1 + esp) cnt++;
        }
        max_cnt = max(max_cnt, cnt);
      }
    }
    cout << max_cnt << endl;
  }
  
  
  return 0;
}
