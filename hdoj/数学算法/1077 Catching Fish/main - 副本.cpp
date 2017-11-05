#include <iostream>
#include <cmath>
const double eps=1e-6;
const int MAXN=305;
struct point
{
    double x,y;
};
struct point ps[MAXN];
int N;
double get_dis(int a,int b)
{
    return (ps[a].x-ps[b].x)*(ps[a].x-ps[b].x)+(ps[a].y-ps[b].y)*(ps[a].y-ps[b].y);
}
void get_center(int a,int b)
{
    double ox,oy,dx,dy,r,temp;
    ox=(ps[a].x+ps[b].x)/2;
    oy=(ps[a].y+ps[b].y)/2;
    dx=ps[b].x-ps[a].x;
    dy=ps[b].y-ps[a].y;
    ps[N].x=ox;ps[N].y=oy;
    temp=get_dis(N,b);
    r=sqrt(1.0-temp);
    if(fabs(dx)<eps)//竖直的情况
        ps[N].x-=r;//+或-都可以
    else
    {
        double ang=atan(-dy/dx);
        ps[N].x-=r*sin(ang);//+或-都可以
        ps[N].y-=r*cos(ang);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int T,i,j,k,max;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
            scanf("%lf%lf",&ps[i].x,&ps[i].y);
        int ans=1;
        for(i=0;i<N;i++)//枚举O(n^2)
        {
            for(j=i+1;j<N;j++)
            {
                if(get_dis(i,j)>=4) continue;
                get_center(i,j);
                for(k=0,max=0;k<N;k++)
                {
                    if(N-k+max<=ans) break;
                    double temp=sqrt(get_dis(k,N));
                    if(temp<=1.000001)
                        max++;
                }
                if(max>ans)
                    ans=max;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
