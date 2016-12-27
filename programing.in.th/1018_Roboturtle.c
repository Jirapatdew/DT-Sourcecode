#include <stdio.h>
#include <stdlib.h>

int x=0,y=0;
int direct=2;


void LT()
{
    if(direct==1) direct=4;
    else direct--;
}
void RT()
{
    if(direct==4) direct=1;
    else direct++;
}
void BW()
{
    if(direct==3) direct=1;
    else if(direct==4) direct=2;
    else direct+=2;
}
int main()
{
    int n,i,s,d=0;
    char ch[4];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s%d",ch,&s);
        if(ch[0]=='L') LT();
        else if(ch[0]=='R') RT();
        else if(ch[0]=='B') BW();
        if(direct==1) y+=s;
        else if(direct==2) x+=s;
        else if(direct==3) y-=s;
        else if(direct==4) x-=s;
        if(x>=50000||x<=-50000||y>=50000||y<=-50000) d=1;
    }
    if(d==0)
    {
        printf("%d %d\n",x,y);
        if(direct==1) printf("N");
        else if(direct==2) printf("E");
        else if(direct==3) printf("S");
        else if(direct==4) printf("W");
    }
    else printf("DEAD");
    return 0;
}
//N=1 E=2 S=3 W=4
