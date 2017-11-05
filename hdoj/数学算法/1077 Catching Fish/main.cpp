#include <bits/stdc++.h>
using namespace std;

struct point
{
  double x;
  double y;
} points[305];

point getCenterpoint(point a, point b, int oo)
{
  point pp = {-1, -1};
  double k = (b.y - a.y) / (b.x - a.x);
  double fk = -1 / k;
  point centerp = {(a.x+b.x)/2, (a.y+b.y)/2};
  double dis = sqrt((b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y));
  if (dis > 2 + 1e-4 + 1e-4) {
    return pp;
  }
  dis = min(2.0, dis);
  double t = sqrt(1 - (dis/2)*(dis/2));
  double beta = atan(fk);
  double delta_x = abs(cos(beta)*t);
  double delta_y = abs(sin(beta)*t);
  pp.x = centerp.x + delta_x*oo;
  pp.y = centerp.y + delta_y*oo;
  return pp;
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
    point cp;
    int count_max = 1;
    for (int j = 0; j < N; ++j) {
      for (int k = j+1; k < N; ++k) {
        cp = getCenterpoint(points[j], points[k], 1);
        if (cp.x == -1 && cp.y == -1) continue;
        int count_ = 0;
        for (int m = 0; m < N; ++m) {
          double dis = sqrt((cp.x-points[m].x)*(cp.x-points[m].x) + (cp.y-points[m].y)*(cp.y-points[m].y));
          if (dis <= 1 + 1e-4) ++count_;
        }
        count_max = max(count_max, count_);
      }
    }
    cout << count_max << endl;
  }

  return 0;
}
