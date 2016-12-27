#include <stdio.h>
#include <stdlib.h>

int d=0,tree[1000][3],n,pre[1000][2],t=0;

int binary(int post[][2],int low,int high,int key)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(post[mid][0]==key) return mid;
        if(mid==high) return -1;
        if(post[mid][0]<key)
        {
            low=mid+1;
        }
        else if(post[mid][0]>key)
        {
            high=mid-1;
        }
    }
}
void create(int x,int p,int lr)
{
    tree[p][lr]=d;
    tree[d][0]=-1;
    tree[d][1]=x;
    tree[d][2]=-1;
    d++;
}
int mt(int k,int x,int p,int lr)
{
    if(k==-1&&t==0) {create(x,p,lr);t=1;}
    if(t==1) return 0;
    if(pre[x][1]<pre[tree[k][1]][1])
    {
        mt(tree[k][0],x,k,0);
        mt(tree[k][2],x,k,2);
    }
    else return 0;
}
int cmp(const void* a,const void* b)
{
    int *aa=(int*)a;
    int *bb=(int*)b;
    if(aa[0]>bb[0]) return 1;
    else return -1;
}
int inorder(int k)
{
    if(tree[k][0]!=-1) inorder(tree[k][0]);
    printf("%d\n",pre[tree[k][1]][0]);
    if(tree[k][2]!=-1) inorder(tree[k][2]);
}
int main()
{
    int i,j,post[1001][2];
    scanf("%d",&n);
    for(i=0; i<n; i++) tree[i][1]=-1;
    for(i=0; i<n; i++) scanf("%d",&pre[i][0]);
    for(i=0; i<n; i++)
    {
        scanf("%d",&post[i][0]);
        post[i][1]=i;
    }
    qsort(post,n,sizeof(post[0]),cmp);
    for(i=0; i<n; i++) pre[i][1]=post[binary(post,0,n-1,pre[i][0])][1];
    tree[0][1]=0;
    tree[0][0]=-1;
    tree[0][2]=-1;
    d++;
    for(i=1; i<n; i++) {t=0;mt(0,i,0,0);}
    inorder(0);
    return 0;
}
