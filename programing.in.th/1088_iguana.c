#include <stdio.h>
#include <stdlib.h>

//use time:0.156
int cmp(const void*a,const void*b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int main()
{
    int n,m,t;
    int i;
    int data[200008][2]={0},total=0,sum=0,p;
    char ch;
    int i_ch;
    scanf("%d%d",&n,&m);
    t=m*2;
    for(i=0;i<t;i+=2)
    {
        scanf("%d%d",&data[i][0],&data[i+1][0]);
        data[i+1][0]++;
        data[i][1]=1;
        data[i+1][1]=-1;
    }
    scanf("\n%c",&ch);
    if(ch=='R') i_ch=0;
    else if(ch=='G') i_ch=1;
    else i_ch=2;
    qsort(data,t,sizeof(data[0]),cmp);

    data[t][0]=n+1;//****** add the end;
    p=1;
    sum=0;
    total=(data[0][0]-p)*(i_ch-sum);

    for(i=0;i<t&&data[i][0]<=data[i+1][0];i++)
    {
        if(data[i][1]==1) sum=(sum+1)%3;
        else if(sum==0) sum=2;
        else sum--;
        if(i_ch>=sum) total+=((data[i+1][0]-data[i][0])*(i_ch-sum));
        else total+=((data[i+1][0]-data[i][0])*(3-(sum-i_ch)));
    }
    printf("%d",total);
    return 0;
}
