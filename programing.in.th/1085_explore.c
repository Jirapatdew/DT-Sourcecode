#include <stdio.h>
#include <stdlib.h>

int max=0;
int room[500005]= {0};
int **tel,*chk_tel,n,m,k;
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}
int walk(int a)
{
    int i,x;
    if(chk_tel[a]>=0)
    {
        i=0;
        x=chk_tel[a];
        chk_tel[a]=-1;
        while(tel[x+i][0]==a&&x+i<m)
        {
            walk(tel[x+i][1]);
            i++;
        }
    }
    if(room[a]==1||a==n)
    {
        if(a>max) max=a;
        return 0;
    }
    walk(a+1);
}
int main()
{
    int a,b,x;
    int i;

    tel=(int**)malloc(sizeof(int*)*1000005);
    for(i=0; i<1000005; i++)
    {
        tel[i]=(int*)malloc(sizeof(int)*2);
    }

    chk_tel=(int*)malloc(sizeof(int)*500005);
    for(i=0; i<500005; i++) chk_tel[i]=-1;

    scanf("%d%d%d",&n,&m,&k);
    for(i=0; i<m; i++) scanf("%d%d",&tel[i][0],&tel[i][1]);
    qsort(tel,m,sizeof(tel[0]),cmp);

    if(m>0)
    {
        a=tel[0][0];
        chk_tel[a]=0;
        for(i=1; i<m; i++)
        {
            if(tel[i][0]!=a)
            {
                a=tel[i][0];
                chk_tel[a]=i;
            }
        }
    }
    for(i=0; i<k; i++)
    {
        scanf("%d",&x);
        room[x]=1;
    }
    walk(1);
    if(max==n) printf("1");
    else printf("0 %d",max);
    return 0;
}
