#include <stdio.h>
#include <stdlib.h>

int min_to_max(int []);
int main()
{
    int a[10],i,j,temp,dt,count=1;
    for(i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]%42;
    }
    for(i=0; i<10; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if(a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    dt=a[0];
    for(i=1;i<10;i++)
    {
        if(a[i]>dt)
        {
            dt=a[i];
            count+=1;
        }
    }
    printf("%d",count);

    return 0;

}
