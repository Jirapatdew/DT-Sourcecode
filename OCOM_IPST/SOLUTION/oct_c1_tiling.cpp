#include <stdio.h>

using namespace std;

int L,n;
struct P{int x,y;P(int _x,int _y){x=_x;y=_y;}};
bool chk(P a,P b,P c)
{
    if(a.x<=b.x&&b.x<=c.x&&a.y<=b.y&&b.y<=c.y) return true;
    else return false;
}
int divide(P up,P dw,P emp)
{
    if(up.x==dw.x&&up.y==dw.y)
        return 0;
    P mid=(P((dw.x+up.x)/2,(dw.y+up.y)/2));
    if(chk(up,emp,mid))
    {
        printf("0 %d %d\n",mid.x,mid.y);
        divide(up,mid,emp);
        divide(P(mid.x+1,up.y),P(dw.x,mid.y),P(mid.x+1,mid.y));//q1
        divide(P(up.x,mid.y+1),P(mid.x,dw.y),P(mid.x,mid.y+1));//q3
        divide(P(mid.x+1,mid.y+1),dw,P(mid.x+1,mid.y+1));
    }
    else if(chk(P(mid.x+1,mid.y+1),emp,dw))
    {
        printf("3 %d %d\n",mid.x,mid.y);
        divide(up,mid,mid);
        divide(P(mid.x+1,up.y),P(dw.x,mid.y),P(mid.x+1,mid.y));
        divide(P(up.x,mid.y+1),P(mid.x,dw.y),P(mid.x,mid.y+1));
        divide(P(mid.x+1,mid.y+1),dw,emp);
    }
    else if(emp.x<=mid.x)//q3
    {
        printf("2 %d %d\n",mid.x,mid.y);
        divide(up,mid,mid);
        divide(P(mid.x+1,up.y),P(dw.x,mid.y),P(mid.x+1,mid.y));
        divide(P(up.x,mid.y+1),P(mid.x,dw.y),emp);
        divide(P(mid.x+1,mid.y+1),dw,P(mid.x+1,mid.y+1));
    }
    else
    {
        printf("1 %d %d\n",mid.x,mid.y);
        divide(up,mid,mid);
        divide(P(mid.x+1,up.y),P(dw.x,mid.y),emp);
        divide(P(up.x,mid.y+1),P(mid.x,dw.y),P(mid.x,mid.y+1));
        divide(P(mid.x+1,mid.y+1),dw,P(mid.x+1,mid.y+1));
    }
}
int main()
{
    P emp(0,0);
    scanf("%d%d%d",&L,&emp.x,&emp.y);
    printf("%d\n",(L*L-1)/3);
    divide(P(0,0),P(L-1,L-1),emp);
    return 0;
}
