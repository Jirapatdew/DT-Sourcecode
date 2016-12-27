#include <stdio.h>
#include <stdlib.h>

int x,i,j=0,tree[200005],l[200005],r[200005],emp[200005]= {0};
void binary(int k)
{
    if(emp[k]==0)
    {
        emp[k]=1;
        tree[k]=x;
        l[k]=++j;
        r[k]=++j;
        printf("*\n");
    }
    else
    {
        if(x>=tree[k])
        {
            printf("R");
            binary(r[k]);
        }
        else
        {
            printf("L");
            binary(l[k]);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&x);
        binary(0);
    }
    return 0;
}
/*char ans[100005][50]= {'\0'};
int x,i,j=0,tree[200005],emp[200005]= {0};
void binary(int k)
{
    if(emp[k]==0)
    {
        emp[k]=1;
        tree[k]=x;
        ans[i][j++]='*';
    }
    else
    {
        if(x>=tree[k])
        {
            ans[i][j++]='R';
            binary(2*k+2);
        }
        else
        {
            ans[i][j++]='L';
            binary(2*k+1);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        j=0;
        scanf("%d",&x);
        binary(0);
    }
    for(i=0; i<n; i++) printf("%s\n",ans[i]);
    return 0;
}
*/
