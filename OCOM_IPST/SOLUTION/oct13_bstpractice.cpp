#include <stdio.h>

using namespace std;
int node[100010]={0},left[100010]={0},right[100010]={0},p[100010]={0};
int idx=1;
int insert(int v,int i)
{
    if(i==1) {printf("*\n");return 0;}
    if(node[i]<node[v])
    {
        printf("L");
        if(left[v]==0) {left[v]=i;p[i]=v;printf("*\n");}
        else insert(left[v],i);
    }
    else if(node[i]>node[v])
    {
        printf("R");
        if(right[v]==0) {right[v]=i;p[i]=v;printf("*\n");}
        else insert(right[v],i);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&node[idx]);
        insert(1,idx);
        idx++;//create new node
    }
    return 0;
}
