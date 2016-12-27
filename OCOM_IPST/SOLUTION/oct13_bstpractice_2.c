#include <stdio.h>
#include <stdlib.h>

int key[100005]={0};
int left[100005]={0};
int right[100005]={0};

int Insert(int x,int idx,int p)
{
    if(x==0)
    {
        if(key[idx]<key[p]) left[p]=idx;
        else right[p]=idx;
        printf("*\n");
    }
    else
    {
        if(key[idx]<key[x]) {printf("L");Insert(left[x],idx,x);}
        else if(key[idx]>key[x]) {printf("R");Insert(right[x],idx,x);}
    }
    return 0;
}

int main()
{
    int n;
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&key[i]);
    printf("*\n");
    for(i=2;i<=n;i++) Insert(1,i,0);

    return 0;
}
