/*
TASK: bomb
LANG: C
AUTHOR: Jirapat Atiwattanachai
CENTER: KKU03
*/
#include <stdio.h>
#include <stdlib.h>


int compare(const void* a,const void* b)
{
     int *aa=(int*)a;
     int *bb=(int*)b;
     if(aa[0]>bb[0]) return 1;
     else if(aa[0]==bb[0]&&aa[1]<bb[1]) return 1;
     else return -1;
}
int main()
{
    int n,i,mx,my;
    int data[1000010][2]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&data[i][0],&data[i][1]);
    qsort(data,n,sizeof(data[0]),compare);
    mx=data[n-1][0];
    my=data[n-1][1];
    for(i=n-2;i>=0;i--)
    {
        if(my<=data[i][1])
        {
            printf("%d %d\n",mx,my);
            mx=data[i][0];
            my=data[i][1];
        }
    }
    printf("%d %d\n",mx,my);
    return 0;
}
