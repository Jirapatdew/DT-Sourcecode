#include <stdio.h>
#include <stdlib.h>
int l[505005]={0};

int cmp(const void*a,const void* b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int n,size,num=0;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&l[i]);
    qsort(l,n,sizeof(l[0]),cmp);
    size=n;
    j=0;
    while(size>1)
    {
        if(l[j]+2<=size) {size-=l[j]+1;num+=l[j];j++;}
        else {num+=size-1;break;}
    }
    printf("%d",num);
    return 0;
}
