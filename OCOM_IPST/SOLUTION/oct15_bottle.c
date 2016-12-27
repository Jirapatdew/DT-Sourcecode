#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
    int *ra,*rb;
    ra=(int*)a;
    rb=(int*)b;
    if(ra[0]<rb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m,data[100005][2]= {0},use[100005]= {0};
    int i,x,d=0,c=0,y=0;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%d",&data[i][0]);
        data[i][1]=i;
    }
    use[n]=1;
    qsort(data,n,sizeof(data[0]),compare);
    for(i=0; i<m; i++)
    {
        y=0;
        scanf("%d",&x);
        while(data[d][0]>x&&d<n)
        {
            if(use[data[d][1]]==0)
            {
                use[data[d][1]]=2;
                y++;
            }
            d++;
        }
        while(data[c][0]>x&&c<n)
        {
            if(use[data[c][1]]==2)
            {use[data[c][1]]=1;
            if(use[data[c][1]+1]==0)
            {
                use[data[c][1]+1]=1;
                y++;
            }
            if(data[c][1]-1>=0&&use[data[c][1]-1]==0)
            {
                use[data[c][1]-1]=1;
                y++;
            }}
            c++;
        }
        c=d;
        printf("%d\n",y);
    }
    return 0;
}
