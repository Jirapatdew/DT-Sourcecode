#include <stdio.h>
#include <stdlib.h>
#include "count.h"

int data[100000],n,k,i,cnt=-1,now=0,a;
int main()
{
    //scanf("%d %d",&n,&k);
    n=GetN();
    k=GetK();
    a=n;
    while(a>0)
    {
        cnt++;
        data[cnt]=a;
        a-=(k+1);
    }
    if(data[cnt]==1) {now=Second(); cnt--;}
    while(now<n)
    {
        //if(now<data[cnt])
        now=Ans(data[cnt]-now-1);
        if(now>=data[cnt]) cnt--;
    }
    return 0;
}
