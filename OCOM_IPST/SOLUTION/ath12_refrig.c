#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,min,p;
    int data[300];
    int i,k,sum=0;
    scanf("%d",&t);
    for(k=0; k<t; k++)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&data[i]);
        }
        while(1)
        {
            min=data[0];
            for(i=0; i<n; i++) if(min>data[i]) min=data[i];
            p=0;
            for(i=0; i<n; i++)
            {
                if(data[i]==min&&p==0) {p=1;}
                else
                {
                    data[i]--;
                    if(data[i]==0) break;
                }
            }
            if(data[i]==0&&i<n) break;
            sum++;
        }
        printf("%d\n",sum+1);
    }

    return 0;
}
