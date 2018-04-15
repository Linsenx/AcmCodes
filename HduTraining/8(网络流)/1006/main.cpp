#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 1000;
const int maxm = 5e5;

struct edge {
  int from, to, cap, flow=0, cost;
  edge(){}
  edge(int a,int b,int c,int d):from(a),to(b),cap(c),cost(d) {}
};

vector<edge> edges;
vector<int> G[maxn];

char mp[105][105];
int cnt_human, cnt_house;
vector<pair<int,int>> human;
vector<pair<int,int>> house;

int addEdge(int from, int to, int cap, int cost)
{
  edges.push_back(edge(from,to,cap,cost));
  edges.push_back(edge(to,from,0,-cost));
  int m = edges.size();
  G[from].push_back(m-2);
  G[to].push_back(m-1);
}

bool inque[maxn];
int cost[maxn], pre[maxn];
bool spfa(int s, int e, int n)
{
  for (int i = 0; i < n; ++i) {
    cost[i] = INF;
    inque[i] = false;
  }
  queue<int> Q;
  Q.push(s);
  cost[s] = 0;
  pre[s] = -1;
  inque[s] = true;

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    inque[u] = false;
    for (int i = 0; i < G[u].size(); ++i) {
      edge e = edges[G[u][i]];
      if (e.cap-e.flow>0 && cost[e.to]>cost[u]+e.cost) {
        cost[e.to] = cost[u]+e.cost;
        pre[e.to] = G[u][i];
        if (!inque[e.to]) {
          Q.push(e.to);
          inque[e.to] = true;
        }
      }
    }
  }

  return cost[e] != INF;
}

int mincost_maxflow(int s, int e, int& mincost, int n)
{
  int ans = 0;
  while (spfa(s, e, n)) {
    int mint = INF;

    for (int i = pre[e]; i != -1; i=pre[edges[i^1].to]) {
      if (mint > edges[i].cap-edges[i].flow) {
        mint = edges[i].cap-edges[i].flow;
      }
    }
    ans += mint;
    for (int i = pre[e]; i != -1; i=pre[edges[i^1].to]) {
      edges[i].flow += mint;
      edges[i^1].flow -= mint;
      mincost += mint*edges[i].cost;
    }
  }
  return ans;
}

void init()
{
  edges.clear();
  for (int i = 0; i < cnt_house+cnt_human+2; ++i) {
    G[i].clear();
  }

  cnt_house = cnt_human = 0;
  human.clear();
  house.clear();
}

void build()
{
  for (int i = 0; i < human.size(); ++i) {
    int x = human[i].first;
    int y = human[i].second;
    addEdge(0, 1+i, 1, 0);
    for (int j = 0; j < house.size(); ++j) {
      int xx = house[j].first;
      int yy = house[j].second;
      addEdge(1+i, cnt_human+1+j, 1, abs(xx-x)+abs(yy-y));
    }
  }

  for (int j = 0; j < house.size(); ++j) {
    int xx = house[j].first;
    int yy = house[j].second;
    addEdge(cnt_human+1+j, cnt_house+cnt_human+1, 1, 0);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef LOCAL_DEBUG
    freopen("in.txt","r",stdin);
  #endif

  char ch;
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    init();

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> mp[i][j];
      if (mp[i][j] == 'm') {
        cnt_human++;
        human.push_back(make_pair(i,j));
      } else if (mp[i][j] == 'H') {
        cnt_house++;
        house.push_back(make_pair(i,j));
      }
    }

    build();
    int mincost = 0;
    mincost_maxflow(0, cnt_house+cnt_human+1, mincost, cnt_house+cnt_human+2);
    cout << mincost << endl;
  }

  return 0;
}
