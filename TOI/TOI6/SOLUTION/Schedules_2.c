#include <stdio.h>
#include <stdlib.h>
#define M 500005

int data[M][2],chk[M]={0};
char ans[M]={'\0'};
int main()
{
    int n,k,m,i,tmp[2],num=0,q;

    scanf("%d%d%d",&n,&k,&m);
    //data=(int**)malloc(sizeof(int*)*M);
    //for(i=0;i<M;i++) data[i]=(int*)malloc(sizeof(int)*2);
    for(i=0;i<M;i++) {data[i][0]=0;data[i][1]=0;}
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&tmp[0],&tmp[1]);
        data[tmp[0]][0]=tmp[1]+1;//[0]=f [1]=Q
        data[tmp[0]][1]=i;
    }
    for(i=0;i<M;i++)
    {
        num+=chk[i];
        if(data[i][0]!=0&&num<k)
        {
            num++;
            chk[data[i][0]]--;
            ans[data[i][1]]='Y';
        }
        else ans[data[i][1]]='N';
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&q);
        printf("%c ",ans[q]);
    }
    return 0;
}
