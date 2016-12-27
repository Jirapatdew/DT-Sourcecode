#include <stdio.h>
#include <stdlib.h>


int compare(const void* a,const void* b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]>bb[1]) return 1;
    else return -1;
}
int main()
{
    int k,n,m;
    int i,max=0;
    int st,sp;
    int input[100010][2]={0};
    int data[100010]= {0};
    scanf("%d%d%d",&k,&n,&m);
    for(i=0; i<m; i++) scanf("%d%d",&input[i][0],&input[i][1]);
    qsort(input,m,sizeof(input[0]),compare);
    for(i=0; i<m; i++)
    {
        st=input[i][0];
        sp=input[i][1];
        if(st==1)
        {
            data[sp]=k-1;
            if(max<sp) max=sp;
        }
        else if(data[st]!=0)
        {
            if(data[sp]<=data[st]-1)
            {
                data[sp]=data[st]-1;
                if(max<sp) max=sp;
            }
        }
    }
    printf("%d",max);
    return 0;
}
