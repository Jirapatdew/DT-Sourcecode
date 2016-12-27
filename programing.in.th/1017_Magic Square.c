#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,data[20][20],TF=1,sum=0,total=0;
    int number[101]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&data[i][j]);
            if(number[data[i][j]]==0) number[data[i][j]]=1;
            else TF=0;
        }
    for(i=0;i<n;i++) sum+=data[0][i];
    for(i=0;i<n;i++)
    {
        total=0;
        for(j=0;j<n;j++) total+=data[i][j];//right
        if(total!=sum) TF=0;

        total=0;
        for(j=0;j<n;j++) total+=data[j][i];//down
        if(total!=sum) TF=0;
    }
    total=0;
    for(i=0;i<n;i++) total+=data[i][i];
    if(total!=sum) TF=0;

    total=0;
    for(i=n-1;i>=0;i--) total+=data[i][i];
    if(total!=sum) TF=0;

     if(TF==1) printf("Yes");
     else  printf("No");
    return 0;
}
