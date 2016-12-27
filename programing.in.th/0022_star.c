#include<stdio.h>

int main()
{
    int n,a,c,d;
    scanf("%d",&n);
    if(n%2==0)a=n-1;
    else a=n;
    int mid=a/2+1;
    for(c=0; c<n/2; c++)
    {
        for(d=1; d<=a; d++)
            if(d==mid-c||d==mid+c) printf("*");
            else printf("-");
        printf("\n");
    }
    if(n==1)printf("*");
    else if(n%2==1)
    {
        printf("*");
        for(d=2; d<a; d++) printf("-");
        printf("*\n");
    }
    for(c=n/2-1; c>=0; c--)
    {
        for(d=1; d<=a; d++)
            if(d==mid-c||d==mid+c) printf("*");
            else printf("-");
        printf("\n");
    }
}
