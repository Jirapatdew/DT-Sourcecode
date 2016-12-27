#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char c[100005][100];
int key[100005]={0},num=1;
int left[100005]={0};
int right[100005]={0};

void print(int i,int j,int k)
{
    if(c[i][j]=='*') printf("%d\n",key[k]);
    else if(c[i][j]=='R') print(i,j+1,right[k]);
    else if(c[i][j]=='L') print(i,j+1,left[k]);
}
int set(int x)
{
    if(x==0) return 0;
    set(left[x]);
    key[x]=num++;
    set(right[x]);
}

int main()
{
    int n,i,j,len;
    int node,d=1;
    scanf("%d\n",&n);
    gets(c[0]);
    key[d++]=1;
    for(i=1;i<n;i++)
    {
        node=1;
        gets(c[i]);
        len=strlen(c[i]);
        for(j=0;j<len-2;j++)
        {
            if(c[i][j]=='L') node=left[node];
            else if(c[i][j]=='R') node=right[node];
        }
        if(c[i][j]=='L'&&left[node]==0)
        {
            left[node]=d;
            key[d++]=1;
        }
        else if(c[i][j]=='R'&&right[node]==0)
        {
            right[node]=d;
            key[d++]=1;
        }
    }
    set(1);
    for(i=0; i<n; i++) print(i,0,1);
    return 0;
}
