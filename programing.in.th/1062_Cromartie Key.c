#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[130]={0},b[130]={0};
    char key[130]={0};
    int l,k;
    int i,j;
    scanf("%d%d",&l,&k);
    scanf("%s",&a);
    scanf("%s",&b);
    scanf("%s",&key);
    for(i=0;i<k;i++)
    {
        for(j=0;j<l;j++)
        {
            if((b[j]>=a[j]&&a[j]>=key[i])||(key[i]>=a[j]&&a[j]>=b[j])) key[i]=a[j];
            else if((a[j]>=b[j]&&b[j]>=key[i])||(key[i]>=b[j]&&b[j]>=a[j])) key[i]=b[j];
        }
    }
    printf("%s",key);
    return 0;
}
