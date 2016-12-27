#include <stdio.h>
#include <stdlib.h>

int data[100]= {0};
int chk[100]={0};
int ans[100]= {0};
int n,p=0;

int cmp(const void*a,const void*b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb) return 1;
    else return -1;
}
int find(int a,int len)
{
    int i;
    if(a==0)
    {
        p=1;
        for(i=0; i<len; i++) printf("%d\n",ans[i]);
    }
    if(a>0)
    {
        for(i=0; i<n; i++)
        {
            if(a>=data[i]&&p==0&&chk[i]==0)
            {
                chk[i]=1;
                ans[len]=data[i];
                find(a-data[i],len+1);
                chk[i]=0;
            }
        }
    }
    return 0;
}
int main()
{
    int m,i;
    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&data[i]);
    qsort(data,n,sizeof(data[0]),cmp);
    scanf("%d",&m);
    find(m,0);
    return 0;
}
