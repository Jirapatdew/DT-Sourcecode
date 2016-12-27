#include <stdio.h>

using namespace std;

int n;
int T[1030][1030]={0};
int update(int x,int y,int v)
{
    for(int i=x;i<=n;i+=(i&-i))
        for(int j=y;j<=n;j+=(j&-j)) T[i][j]+=v;
}
int freqTo(int x,int y)
{
    int sum=0;
    for(int i=x;i>0;i-=(i&-i))
        for(int j=y;j>0;j-=(j&-j)) sum+=T[i][j];
    return sum;
}
int freqFrom(int x1,int y1,int x2,int y2)
{
    return freqTo(x2,y2)-freqTo(x1-1,y2)-freqTo(x2,y1-1)+freqTo(x1-1,y1-1);
}
int main()
{
    int c=0,x,y,v;
    int l,b,r,t;
    scanf("0 %d",&n);
    while(1)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d%d%d",&x,&y,&v);
            update(x+1,y+1,v);
        }
        else if(c==2)
        {
            scanf("%d%d%d%d",&l,&v,&r,&t);
            printf("%d\n",freqFrom(l+1,v+1,r+1,t+1));
        }
        else break;
    }
    return 0;
}
