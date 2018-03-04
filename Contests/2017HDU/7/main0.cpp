#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))

const int N=200;
const int INF=0x3f3f3f3f;
int mp[N][N];
int suf[N][N];
int main()
{
  ios::sync_with_stdio(false);
  #ifdef ONLINE_JUDGE
  #else
    freopen("in.txt","r",stdin);
  #endif
    cin.tie(0);
    int T;
    int n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        mem(suf,INF);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>mp[i][j],suf[i][j]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=i+1;k<n;k++)
                {
                    if(mp[k][j]!=mp[k-1][j])suf[k][j]=min(suf[k][j],i);
                    else break;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int t=suf[i][j];
                ans=max(ans,i-t+1);
                for(int k=j-1;k>=0;k--)
                {
                    t=max(t,suf[i][k]);
                    if(mp[i][k]!=mp[i][k+1])
                    {
                        ans=max(ans,(j-k+1)*(i-t+1));
                    }
                    else break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
