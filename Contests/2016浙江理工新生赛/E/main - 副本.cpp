/**
* 行有余力，则来刷题！
  * 博客链接:http://blog.csdn.net/hurmishine
  *
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int month[2][12]=
{
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};
int Leap(int y)//闰年
{
    if(y%400==0||y%100!=0&&y%4==0)
        return 1;
    return 0;

}
int solve(int y,int m,int d)
{
    int sum=0;
    if(y==2017)
    {
        if(m==10)
            sum=28-d;
        else
        {
            sum=month[0][m-1]-d+27;
            for(int i=m; i<9; i++)
                sum+=month[0][i];
        }
    }
    else
    {
        int flag=Leap(y);
        sum=month[flag][m-1]-d+301;
        for(int i=m; i<12; i++)
            sum+=month[flag][i];
    }
    for(int i=y+1; i<2017; i++)
        sum+=(365+Leap(i));
    return sum;
}
int main()
{
    int T;
    freopen("in.txt","r",stdin);
    //freopen("me.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        int y,m,d;
        cin>>y>>m>>d;
        cout<<solve(y,m,d)<<endl;
    }
    return 0;
}
