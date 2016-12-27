#include <stdio.h>
#include <stdlib.h>

int key[200005]={0};
int left[200005]={0};
int right[200005]={0};
int TreeSearch(int x,int k)
{
    if(x==0||key[x]==k) return x;
    if(k<key[x]) return TreeSearch(left[x],k);
    else return TreeSearch(right[x],k);
}
int Insert(int x,int idx,int p)
{
    if(x==0)
    {
        if(key[idx]<key[p]) left[p]=idx;
        else right[p]=idx;
    }
    else
    {
        if(key[idx]<key[x]) Insert(left[x],idx,x);
        else if(key[idx]>key[x]) Insert(right[x],idx,x);
    }
    return 0;
}
int main()
{
    int n,m,a;
    int i,root;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)   scanf("%d",&key[i]);
    root=1;//root node is random
    for(i=1;i<=n;i++) Insert(root,i,0);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a);
        if(TreeSearch(root,a)==0) printf("n\n");
        else printf("y\n");
    }

    return 0;
}
