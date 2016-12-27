#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,j,i,k,a[1005]= {0},temp,d;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    for(i=1; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(a[i-1]==0)
        {
                d=a[i]+1;
                k=i-1;
                while(a[k]<=d&&k>=0)
                {
                    a[k]=d;
                    d++;
                    k--;
                }
                continue;
        }
        for(j=i; j>0; j--)
        {
            if(a[j]>a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1]-1;
                a[j-1]=temp-1;
            }
            else if(a[j]==a[j-1]) a[j]=a[j-1]-1;
            else break;
        }
    }
    for(i=0; i<n; i++) printf("%d\n",a[i]);
    return 0;
}
