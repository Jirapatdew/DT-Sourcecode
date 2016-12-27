#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[100001]={0};
    int leader[100001]={0};
    int x,y;
    int m,n;
    int i;
    int win,lose;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        while(leader[x]!=0) x=leader[x];
        while(leader[y]!=0) y=leader[y];
        if(x==y) printf("-1\n");
        else
        {
            if(data[x]>data[y]) {win=x;lose=y;}
            else if(data[y]>data[x]) {win=y;lose=x;}
            else if(x<y) {win=x;lose=y;}
            else {win=y;lose=x;}
            printf("%d\n",win);
            leader[lose]=win;
            data[win]+=data[lose]/2;
        }
    }
    return 0;
}
