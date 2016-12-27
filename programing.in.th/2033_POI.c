#include <stdio.h>
#include <stdlib.h>

int input[2005][2005]={0};
int score[2005]={0};
int data[2005][3]={0};

int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]<bb[0]) return 1;
    else if(aa[0]==bb[0]&&aa[1]<bb[1]) return 1;
    else if(aa[0]==bb[0]&&aa[1]==bb[1]&&aa[2]>bb[2]) return 1;
    else return -1;
}
int main()
{
    int n,t,p;
    int i,j;
    /*int **input;
    input=(int**)malloc(sizeof(int*)*2005);
    for(i=0;i<2005;i++) input[i]=(int*)malloc(sizeof(int)*2005);*/

    scanf("%d%d%d",&n,&t,&p);
    for(i=0;i<n;i++)
    {
        for(j=0;j<t;j++)
        {
            scanf("%d",&input[i][j]);
            if(input[i][j]==0) score[j]++;
        }
    }
    for(i=0;i<n;i++)
    {
        data[i][2]=i;
        for(j=0;j<t;j++)
        {
            if(input[i][j]==1) {data[i][0]+=score[j];data[i][1]++;}
        }
    }
    qsort(data,n,sizeof(data[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(data[i][2]==p-1)
        {
            printf("%d %d",data[i][0],i+1);
            break;
        }
    }
    return 0;
}
