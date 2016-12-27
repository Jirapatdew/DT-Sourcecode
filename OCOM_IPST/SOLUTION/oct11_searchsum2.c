#include <stdio.h>
#include <stdlib.h>

int book[1005],min[1005]={0};
void binary_search(a,low,high)
{
    int middle = (low + high)/2;
    if(low<high)
    {
        if (a >= min[middle+1])
            binary_search(a, middle+1, high);
        else if (a <= min[middle])
            binary_search(a,low,middle);
        else printf("%d\n",middle);
    }
    else printf("%d\n",middle);
}
int main()
{
    int n,k,i,j,x,a;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&book[i]);
        book[i]+=book[i-1];
        min[i]=1000000000;
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            x=book[j]-book[i-1];
            if(min[j-i+1]>x) min[j-i+1]=x;
        }
    }
    for(i=0; i<k; i++)
    {
        scanf("%d",&a);
        binary_search(a,0,n);
    }

    return 0;
}
