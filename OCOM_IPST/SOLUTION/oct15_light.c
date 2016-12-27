#include <stdio.h>
#include <stdlib.h>

int light[100005]={0};
int binary_search(a,low,high)
{
    int middle = (low + high)/2;
    if(low<high)
    {
        if (a >= light[middle+1])
            binary_search(a, middle+1, high);
        else if (a <= light[middle])
            binary_search(a,low,middle);
        else return middle;
    }
    else return middle;
}
int cmpl(const void* a,const void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int n,m,space[50005][2]={0};
    int i,j,x=0,y=0,a=0,b=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d%d",&space[i][0],&space[i][1]);
    for(i=0;i<m;i++) scanf("%d",&light[i]);
    qsort(light,m+1,sizeof(light[0]),cmpl);
    for(i=0;i<n;i++)
    {
        a=binary_search(space[i][1],0,m);
        b=binary_search(space[i][0],0,m);
        y+=a-b;
        if(light[a]==space[i][1]) y--;
    }
    printf("%d",y%2007);
    return 0;
}
/*int cmpsp(const void *a,const void *b)
{
    int *ra,*rb;
    ra=(int*)a;
    rb=(int*)b;
    if(ra[0]>rb[0]) return 1;
    else if(ra[0]==rb[0]&&ra[1]>rb[1]) return 1;
    else return -1;
}
int cmpl(const void* a,const void* b)
{
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int n,m,space[50005][2]={0},light[100005]={0};
    int i,j,x=0,y=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%d%d",&space[i][0],&space[i][1]);
    for(i=0;i<m;i++) scanf("%d",&light[i]);
    qsort(space,n,sizeof(space[0]),cmpsp);
    qsort(light,m,sizeof(light[0]),cmpl);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(light[j]<=space[i][0]) x++;
            else if(light[j]>space[i][0]&&light[j]<space[i][1]) y++;
            else if(light[j]>=space[i][1]) break;
        }
    }
    printf("%d",y%2007);
    return 0;
}*/
