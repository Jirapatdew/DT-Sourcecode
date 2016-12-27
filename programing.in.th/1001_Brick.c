#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,y[20],j,count=0,k;
    char x[21][21]={{'\0'}};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) scanf("%s",x[i]);
    for(j=0;j<m;j++) scanf("%d",&y[j]);
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            if(x[i][j]=='.') ++count;
            else break;
        }
        for(k=0;k<y[j];k++)
        {
            --count;
            if(count==-1) break;
            else x[count][j]='#';
        }
        count=0;
    }
    for(i=0;i<n-1;i++) printf("%s\n",x[i]);
    printf("%s",x[n-1]);
    return 0;
}
