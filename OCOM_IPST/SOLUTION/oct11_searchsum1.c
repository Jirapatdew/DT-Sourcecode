#include <stdio.h>
#include <stdlib.h>

int book[100005]= {0};
void binary_search(a,low,high)
{
    int middle = (low + high)/2;
    if(low<high)
    {
        if (a >= book[middle+1])
            binary_search(a, middle+1, high);
        else if (a <= book[middle])
            binary_search(a,low,middle);
        else printf("%d\n",middle);
    }
    else printf("%d\n",middle);
}
int main()
{
    int i,j,n,k,s=0,a;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&book[i]);
        book[i]+=book[i-1];
    }
    for(i=0; i<k; i++)
    {
        scanf("%d",&a);
        binary_search(a,0,n);
    }
    return 0;
}

