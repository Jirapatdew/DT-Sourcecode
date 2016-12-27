#include <stdio.h>
#include <stdlib.h>
#define M 1005

int main()
{
    int k,i,j,l;
    int n,m,sum,total=0,max=0;
    char data[M][M]={'\0'};
    //short int right[M][M]={0}; /*****/ M*M*4 int + M*M*1 char > 64 MB §§ææææ
    short int down[M][M]={0};
    short int up[M][M]={0};
    short int left[M][M]={0};
    scanf("%d",&k);
    for(l=0;l<k;l++)
    {
        scanf("%d%d\n",&m,&n);
        for(i=0;i<m;i++) gets(data[i]);
        /*for(i=1;i<=m;i++)//right
        {
            sum=0;
            for(j=1;j<=n;j++)
            {
                sum++;
                if(data[i-1][j-1]=='0') {right[i][j]=0;sum=0;}
                else right[i][j]=sum;
            }
        }*/
        for(i=m;i>=1;i--)//left
        {
            sum=0;
            for(j=n;j>=1;j--)
            {
                sum++;
                if(data[i-1][j-1]=='0') {left[i][j]=0;sum=0;}
                else left[i][j]=sum;
            }
        }
        for(j=1;j<=n;j++)//down
        {
            sum=0;
            for(i=1;i<=m;i++)
            {
                sum++;
                if(data[i-1][j-1]=='0') {down[i][j]=0;sum=0;}
                else down[i][j]=sum;
            }
        }
        for(j=n;j>=1;j--)//up
        {
            sum=0;
            for(i=m;i>=1;i--)
            {
                sum++;
                if(data[i-1][j-1]=='0') {up[i][j]=0;sum=0;}
                else up[i][j]=sum;
            }
        }
        for(i=1;i<=m;i++)
        {
            sum=0;
            for(j=1;j<=n;j++)//***invert
            {
                sum++;
                if(data[i-1][j-1]=='0') {sum=0;continue;}
                total=0;
                if(left[i][j+1]>(sum-1)&&j<n) total+=left[i][j+1];
                else total+=(sum-1);
                if(up[i+1][j]>down[i-1][j]&&i<m) total+=up[i+1][j];
                else total+=down[i-1][j];
                total++;
                if(total>max) max=total;
            }
        }
        printf("%d\n",max);
        max=0;
    }
    return 0;
}
