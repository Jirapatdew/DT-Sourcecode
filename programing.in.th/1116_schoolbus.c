#include <stdio.h>
#include <stdlib.h>
int a[1000009]={0};
int main()
{
    int n;
    int i,min;
    double delta=0,x;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    min=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        if(min>a[i]) min=a[i];
        x=(a[i]-min)/2.0;
        if(delta<x) delta=x;
    }
    printf("%.6lf",delta);

    return 0;
}
