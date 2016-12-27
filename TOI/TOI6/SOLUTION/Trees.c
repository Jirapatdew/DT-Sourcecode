/*
TASK: Trees
LANG: C
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int s1,s2,y=1;
    int r;
    char ans[6]={'\0'};
    for(r=0; r<5; r++)
    {
        int x[100001]= {0};
        y=1;
        scanf("%d",&n);
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&s1,&s2);
            if(x[s1]==0) x[s1]=s2;
            else x[s2]=s1;
        }
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&s1,&s2);
            if(x[s1]!=s2&&x[s2]!=s1)
            {
                y=0;
            }
        }
        if(y==0) ans[r]='N';
        else ans[r]='Y';
    }
    printf("%s",ans);
    return 0;
}
