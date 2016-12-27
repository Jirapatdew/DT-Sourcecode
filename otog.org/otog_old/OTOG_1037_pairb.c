#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int n;
    int i,j,min=2000000000,sum=0,m;
    int data[2012]={0};
    scanf("%d",&n);
    m=2*n+1;
    for(i=0;i<m;i++) scanf("%d",&data[i]);
    qsort(data,m,sizeof(int),cmp);
    for(i=0;i<m;i++)
    {
        sum=0;
        for(j=0;j<m-1;j+=2)
        {
            if(j==i) j--;
            else if(j+1==i)
            {
                sum+=abs(data[j]-data[j+2]);
                j++;
            }
            else sum+=abs(data[j]-data[j+1]);
        }
        if(sum<min) min=sum;
    }
    printf("%d",min);
    return 0;
}
