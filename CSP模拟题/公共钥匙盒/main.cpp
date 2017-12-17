#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct t {
  int room;
  int time;
};

int keys[1000+10];
t times[2000+20];
int N, K;
int w, s, c;

bool cmp0(t a, t b)
{
  if (a.time == b.time) {
    if (a.room < 0 && b.room < 0)  {
      return a.room > b.room;
    } else if (a.room * b.room < 0) {
      return a.room < 0;
    }
  } else {
    return a.time < b.time;
  }
}

int main()
{

  freopen("in.txt","r",stdin);

  cin >> N >> K;
  memset(keys, 0, sizeof(keys));
  memset(times, 0, sizeof(times));
  for (int i = 1; i <= N; ++i) keys[i] = i;

  for (int j = 0; j < K*2; j+=2) {
    cin >> w >> s >> c;
    times[j].room = w;
    times[j].time = s;
    times[j+1].room = -w;
    times[j+1].time = s+c;
  }
  sort(times, times + K * 2, cmp0);

  for (int j = 0; j < K*2; j++) {
    //cout << times[j].room << " => " << times[j].time << endl;
    if (times[j].room < 0) {
      int room = -times[j].room;
      for (int v = 1; v <= N; v++) {
        if (keys[v] == 0) {
          keys[v] = room;
          break;
        }
      }
    } else {
      int room = times[j].room;
      for (int v = 1; v <= N; v++) {
        if (keys[v] == room) {
          keys[v] = 0;
          break;
        }
      }
    }
  }

  cout << keys[1];
  for (int i = 2; i <= N; ++i) cout << " " << keys[i];
  return 0;
}
