#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int N[100010]={0},L[100010]={0},R[100010]={0};
char ch[100010];
int idx=1,num=1;
int len,chk=0;
int create(int i,int a)
{
    if(a==len-1)
    {
        if(chk==0) {++idx;N[idx]=-i;}
        return 0;
    }
    if(ch[a]=='L')
    {
        if(L[i]==0) {L[i]=++idx;chk=1;}
        create(L[i],a+1);
    }
    else
    {
        if(R[i]==0) {R[i]=++idx;chk=1;}
        create(R[i],a+1);
    }
    return 0;
}
int inorder(int i)
{
    if(L[i]!=0) inorder(L[i]);
    N[i]=num++;
    if(R[i]!=0) inorder(R[i]);
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",ch);
        len=strlen(ch);
        chk=0;
        if(i==0) chk=1;
        create(1,0);
    }
    inorder(1);
    for(int i=1;i<=idx;i++)
        if(N[i]>0) printf("%d\n",N[i]);
        else printf("%d\n",N[-N[i]]);
    return 0;
}
