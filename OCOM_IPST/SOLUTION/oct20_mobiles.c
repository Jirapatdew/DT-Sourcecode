#include <stdio.h>
#include <stdlib.h>

int Max_x,Max_y;
int tree[1055][1055]={0};
void update(int x,int y,int val)
{
    int y1;
    while(x<=Max_x)
    {
        y1=y;
        while(y1<=Max_y)
        {
            tree[x][y1]+=val;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
int freqTo(int x,int y)
{
    int sum=0,y1;
    while(x>0)
    {
        y1=y;
        while(y1>0)
        {
            sum+=tree[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return sum;
}
int main()
{
    int s;
    int i,j,c,x,y,a,l,b,r,t,sum;

    while(1)
    {
        scanf("%d",&c);
        if(c==3) break;
        if(c==1)
        {
            scanf("%d%d%d",&x,&y,&a);
            x++;y++;
            update(x,y,a);
        }
        else if(c==2)
        {
            scanf("%d%d%d%d",&l,&b,&r,&t);
            l++;b++;r++;t++;
            sum=freqTo(r,t)-freqTo(r,b-1)-freqTo(l-1,t)+freqTo(l-1,b-1);
            printf("%d\n",sum);
        }
        else if(c==0)
        {
            scanf("%d",&s);
            Max_x=s;
            Max_y=s;
        }
    }
    return 0;
}
