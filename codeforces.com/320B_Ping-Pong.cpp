#include <stdio.h>
#define a in[num][0]
#define b in[num][1]
#define c in[j][0]
#define d in[j][1]

using namespace std;
int link[105][105]={0};
int in[105][2]={0},num=0;
int chk[105]={0};
int rec(int x,int y)
{
    if(link[x][y]==1) return 1;
    for(int i=0;i<num;i++)
    {
        if(link[x][i]==1&&chk[i]==0)
        {
            chk[i]=1;
            if(rec(i,y)) return 1;
        }
    }
    return 0;
}
int main()
{
    int n,cc,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&cc);
        if(cc==1)
        {
            scanf("%d%d",&a,&b);
            for(int j=0;j<num;j++)
            {
                if((c<a&&a<d)||(c<b&&b<d)) link[num][j]=1;
                if((a<c&&c<b)||(a<d&&d<b)) link[j][num]=1;
            }
            num++;
        }
        else
        {
            scanf("%d%d",&x,&y);
            x--;y--;
            for(int j=0;j<num;j++) chk[j]=0;
            chk[x]=1;
            if(rec(x,y)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}