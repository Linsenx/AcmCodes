#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int A, B, C, vis[MAXN][MAXN][MAXN];

struct status
{
  int a, b, c, cnt;
};

bool check(status &a)
{
  return vis[a.a][a.b][a.c] == 0;
}

void mark(status &a)
{
  vis[a.a][a.b][a.c] = 1;
}

void bfs()
{
  queue<status> q;
  status now, next;
  now.a = A; 
  now.b = 0;
  now.c = 0;
  now.cnt = 0;
  q.push(now);
  
  int V = 0;
  while (!q.empty())
  {
    now = q.front(); q.pop();
    
//    if (!check(now)) continue;
//    mark(now);
    
//    cout << now.a << "-" << now.b << "-" << now.c <<endl;
    //A B C
    if ((now.a == A/2 && now.b == A/2) ||
        (now.a == A/2 && now.c == A/2) ||
        (now.b == A/2 && now.c == A/2))
        {
          printf("%d\n", now.cnt);
          return;
        }
    
    //可乐瓶中还有
    if (now.a > 0)
    {
      // a -> b
      if (B - now.b > 0)
      {
        V = min(now.a, B - now.b);
        next.a = now.a - V;
        next.b = now.b + V;
        next.c = now.c;
        
        if (check(next)) 
        {
          mark(next);
          next.cnt = now.cnt + 1;
          q.push(next);
        }
      }
      // a -> c
      if (C - now.c > 0)
      {
        V = min(now.a, C - now.c);
        next.a = now.a - V;
        next.b = now.b;
        next.c = now.c + V;
        
        if (check(next))
        {
          mark(next);
          next.cnt = now.cnt + 1;
          q.push(next);
        }
      }
    }
    
    if (now.b > 0)
    {
      // b -> a
      if (A - now.a > 0)
      {
        V = min(now.b, A - now.a);
        next.b = now.b - V;
        next.a = now.a + V;
        next.c = now.c;
        
        if (check(next)) 
        {
          mark(next);
          next.cnt = now.cnt + 1;
          q.push(next);
        }
      }
      // b -> c
      if (C - now.c > 0)
      {
        V = min(now.b, C - now.c);
        next.b = now.b - V;
        next.c = now.c + V;
        next.a = now.a;
        if (check(next)) 
        {
          mark(next);
          next.cnt = now.cnt + 1;
          q.push(next);
        }
      }
    }
    
    if (now.c > 0)
    {
      // c -> a
      if (A - now.a > 0)
      {
        V = min(now.c, A - now.a);
        next.c = now.c - V;
        next.a = now.a + V;
        next.b = now.b;
        if (check(next)) 
        {
          mark(next);
          next.cnt = now.cnt + 1;
          q.push(next);
        }
      }
      // c -> b
      if (B - now.b > 0)
      {
        V = min(now.c, B - now.b);
        next.c = now.c - V;
        next.a = now.a;
        next.b = now.b + V;
        if (check(next))
        {
          mark(next);
          next.cnt = now.cnt + 1;
          q.push(next);
        }
      }
    }
  }
  printf("NO\n");
}

int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif

  while (cin >> A >> B >> C)
  {
    if (A == 0 || B == 0 || C == 0) break;
    memset(vis, 0, sizeof(vis));
    if (A % 2 == 0)
      bfs();
    else
      printf("NO\n");
  }
  
  return 0;
}
