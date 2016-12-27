#include <stdio.h>
#include <stdlib.h>
#define MAXIND 1000005
#define MAXN 300005
using namespace std;
//RMQ Range Minimum/Maximum Query Problems
//node 1-N
int M[MAXIND]={0};
int A[MAXN]={0};
int leaf[MAXIND]={0};

void initialize(int node, int b, int e)
{
    if(b==e) {M[node]=b;leaf[b]=node;}
    else
    {
        //compute the values in the left and right subtrees
        initialize(2*node,b,(b+e)/2);
        initialize(2*node+1,(b + e)/2+1,e);
        //search for the minimum value in the first and
        //second half of the interval
        if(A[M[2*node]]>=A[M[2*node+1]]) M[node]=M[2*node];
        else M[node]=M[2*node+1];
    }
}
int query(int node,int b,int e,int i, int j)
{
    int p1, p2;
    //if the current interval doesn't intersect
    //the query interval return -1
    if (i>e||j<b) return -1;
    //if the current interval is included in
    //the query interval return M[node]
    if (b>=i&&e<=j) return M[node];
    //compute the minimum position in the
    //left and right part of the interval
    p1=query(2*node,b,(b + e)/2,i,j);
    p2=query(2*node+1,(b + e)/2+1,e,i,j);
    //return the position where the overall
    //minimum is
    if (p1==-1) return p2;
    if (p2==-1) return p1;
    if(A[p1]>=A[p2]) return p1;
    return p2;

}

int main()
{
    int n;
    int q;
    int i,j,x,y,e,p;
    char c[5];
    scanf("%d",&n);
    scanf("%d",&q);
    initialize(1,1,n);
    for(i=0; i<q; i++)
    {
        scanf("%s%d%d",c,&x,&y);
        if(c[0]=='U')
        {
            A[x]=y;

            e=leaf[x];
            while(e>1)
            {
                p=e/2;
                if(A[M[p]]<=A[M[p*2]]) M[p]=M[p*2];
                if(A[M[p]]<=A[M[p*2+1]]) M[p]=M[p*2+1];
                //else break;
                e=p;

            }
        }
        else
        {
            printf("%d\n",A[query(1,1,n,x,y)]);
        }
    }
    return 0;
}
