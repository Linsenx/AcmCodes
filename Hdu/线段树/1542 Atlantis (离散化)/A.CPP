
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE=505;
int add[SIZE<<2];                               //add为区间标记，与懒惰标记类似
double x[SIZE<<2],sum[SIZE<<2];
struct node{
    int ss;                                     //ss=1为下边，ss=-1为上边
    double l,r,h;                               //分别记录线段的左端，右端和高度
    node(){}
    node(double a,double b,double c,int d):l(a),r(b),h(c),ss(d){}
    friend bool operator<(node p,node q){       //因为是从下到上扫描因此，需要按照高度排序
        return p.h<q.h;
    }
}s[SIZE];
void pushup(int rt,int l,int r){
    if(add[rt]) {
                          cout <<"f";//这就是如何解决的线段重叠的办法,如果当前区间
    sum[rt]=x[r+1]-x[l];
    }                          //有标记用x数组更新，而不是左右儿子更新
    else if(l==r)
    sum[rt]=0;
    else
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];            //与懒惰标记的区别在于标记不会消失(除非遇到上边)
}                                               //这也就是线段不会重复相加减的关键
void update(int L,int R,int c,int l,int r,int rt){
    int m;
    if(L<=l&&r<=R){
        add[rt]+=c;                             //update与普通线段树基本相同
        pushup(rt,l,r);
        return;
    }
    m=(l+r)>>1;
    if(L<=m)
    update(L,R,c,l,m,rt<<1);
    if(R>m)
    update(L,R,c,m+1,r,rt<<1|1);
    pushup(rt,l,r);
}
int main(){
  freopen("in.txt","r",stdin);                                 //用的是从下到上扫描，也就是扫描线，又因为
    int n,i,k,l,m,r,cas;                        //x坐标可能过多，因此需要对x轴进行离散化,从
    double a,b,c,d,ans;                         //下到上扫描也就是遇到下边进行成段加1，遇到
    cas=1;                                      //上边就是成段减1，所以问题就变成了线段树成
    while(scanf("%d",&n)!=EOF&&n){              //段更新，但我们还需要解决线段重叠的问题，只
        k=1,ans=m=0;                            //要修改pushup就能巧妙的解决这个问题
        for(i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            x[m]=a;
            s[m++]=node(a,c,b,1);
            x[m]=c;
            s[m++]=node(a,c,d,-1);
        }
        sort(x,x+m);
        sort(s,s+m);
        for(i=1;i<m;i++)                        //对x坐标进行离散化，也可以用set
        if(x[i]!=x[i-1])
        x[k++]=x[i];
        memset(add,0,sizeof(add));
        memset(sum,0,sizeof(sum));
        for(i=0;i<m-1;i++){
            l=lower_bound(x,x+k,s[i].l)-x;
            r=lower_bound(x,x+k,s[i].r)-x-1;
            cout << s[i].h << "->" << s[i].ss << endl;
            update(l,r,s[i].ss,0,k-1,1);        //r需要减1，这也是与普通线段树的区别,普通
            ans+=(sum[1]*(s[i+1].h-s[i].h));
        }                                       //对[1,2]和[2,3]区间都加1，普通线段树中2
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",cas++,ans);
    }                                           //那个点会变成2，而这个是表示的线段,因此
    return 0;                                   //2应该为1，因此用左闭右开区间
}
