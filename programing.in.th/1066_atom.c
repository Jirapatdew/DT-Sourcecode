#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//re=remaining
//pc=crossing point;
int main()
{
    int n,i,x,re,total=0,st=0,max,d=0,pb=0,pc;
    int data[1010]={0};
    int link[1010]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++) {scanf("%d",&data[i]);link[i]=i+1;}
    link[n-1]=0;
    re=n;
    st=0;
    while(re>1)
    {
        pb=st;
        x=abs(data[st]-data[link[st]]);
        max=x;d=st;pc=st;
        i=link[st];
        while(link[i]!=0)//find max
        {
            x=abs(data[i]-data[link[i]]);
            if(max<x){max=x;d=i;pc=pb;}
            pb=i;
            i=link[i];
        }
        if(d==st) st=link[link[d]];
        else link[pc]=link[link[d]];
        re-=2;
        total+=max;
    }
    printf("%d",total);
    return 0;
}
