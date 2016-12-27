#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char c[100005];
int key[100005]={0},num=1;
int left[100005]={0};
int right[100005]={0};



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
    gets(c);
    key[d++]=1;
    for(i=1;i<n;i++)
    {
        node=1;
        gets(c);
        len=strlen(c);
        for(j=0;j<len-2;j++)
        {
            if(c[j]=='L') node=left[node];
            else if(c[j]=='R') node=right[node];
        }
        if(c[j]=='L') left[node]=d;
        else if(c[j]=='R') right[node]=d;
        key[d++]=1;
    }
    set(1);
    for(i=1;i<=n;i++) printf("%d\n",key[i]);
    return 0;
}
