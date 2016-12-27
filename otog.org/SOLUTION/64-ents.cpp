#include <stdio.h>

using namespace std;
int data[10000005]={0};
int main()
{
    int i,p,k;
    scanf("%d%d",&k,&p);
    data[2]=1;
    for(i=3;i<=k;i++)
    {
        if(i%2==0) data[i]+=data[i/2];
        data[i]+=data[i-1];
        data[i]%=p;
    }
    printf("%d",data[k]%p);
    return 0;
}
