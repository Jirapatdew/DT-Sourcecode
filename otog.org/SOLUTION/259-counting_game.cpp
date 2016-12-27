#include "count.h"
#include <stdio.h>
using namespace std;

int chk[100005]={0};
int main()
{
    int n,k;
    int Number=2;
    int num=0;
    n=GetN();
    k=GetK();
    for(int i=n-1;i>0;i-=(k+1)) chk[i]=1;
    for(int i=1;i<=k;i++)
    {
        if(chk[i]==1) {Number=1;break;}
    }
    if(Number==2) num=Second();
    while(num<n)
    {
        for(int i=num+1;i<=num+k;i++)
        {
            if(chk[i]==1)
            {
                num=Ans(i-num);
                break;
            }
        }
    }

    return 0;
}
