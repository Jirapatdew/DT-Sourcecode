#include <stdio.h>
#include <stdlib.h>
int data[1000005]={0};
int right[2000005]={0};
int main()
{
    int n,k,idx;
    int i,num;
    long long sum=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) {scanf("%d",&data[i]);if(data[i]==k)idx=i;}
    for(i=0;i<=idx;i++)
    num=0;
    for(i=idx+1;i<n;i++)
    {
        if(data[i]>k) num++;
        else if(data[i]<k) num--;
        right[num+1000000]++;
    }
    num=0;
    for(i=idx-1;i>=0;i--)
    {
        if(data[i]>k) num++;
        else if(data[i]<k) num--;
        if(num==0) sum++;
        sum+=right[1000000-num];
    }
    printf("%lld",sum+right[1000000]+1);
    return 0;
}
