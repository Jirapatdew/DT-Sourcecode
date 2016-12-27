#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,c;
    int i,j,num,pass;
    int x[5],y[5],sum[5];
    char data[105][105]={'\0'};
    scanf("%d%d\n",&r,&c);
    for(i=0;i<r;i++) gets(data[i]);
    num=0;
    pass=0;
    for(i=0;i<r;i++)
    {
        x[0]=i;
        for(j=0;j<c;j++)
        {
            if(data[i][j]=='x')
            {
                num++;
                pass=1;
                y[0]=j;
            }
        }
        if(pass==1) break;
    }
    sum[0]=num;
    num=0;
    pass=0;
    for(i=r-1;i>=0;i--)
    {
        x[1]=i;
        for(j=0;j<c;j++)
        {
            if(data[i][j]=='x')
            {
                num++;
                pass=1;
                y[1]=j;
            }
        }
        if(pass==1) break;
    }
    sum[1]=num;
    num=0;
    pass=0;
    for(j=0;j<c;j++)
    {
         y[2]=j;
         for(i=0;i<r;i++)
         {
            if(data[i][j]=='x')
            {
                num++;
                pass=1;
                x[2]=i;
            }
         }
         if(pass==1) break;
    }
    sum[2]=num;
    num=0;
    pass=0;
    for(j=c-1;j>=0;j--)
    {
         y[3]=j;
         for(i=0;i<r;i++)
         {
            if(data[i][j]=='x')
            {
                num++;
                pass=1;
                x[3]=i;
            }
         }
         if(pass==1) break;
    }
    sum[3]=num;
    pass=0;

    if(sum[0]==sum[1]&&sum[2]==sum[3])
    {
        if(sum[0]>sum[2]) {printf("%d %d %d\n",x[0]+1,y[2]+1,sum[2]);printf("%d %d %d\n",x[0]+1,y[2]-sum[2]+2,sum[2]);}
        else if(sum[0]<sum[2]) {printf("%d %d %d\n",x[0]+1,y[2]+1,sum[0]);printf("%d %d %d\n",x[0]-sum[0]+2,y[2]+1,sum[0]);}
    }
    if(sum[0]==sum[1]&&sum[0]==sum[2]&&sum[0]==sum[3]&&x[1]==x[3]&&y[1]==y[3]&&x[2]==x[1]&&y[1]==y[0])
    {printf("%d %d %d\n",x[0]+1,y[2]+1,sum[0]);printf("%d %d %d\n",x[0]+1,y[2]+1,1);}
    else if(sum[0]==sum[1]&&sum[0]==sum[2]&&sum[0]!=sum[3])
    {
        printf("%d %d %d\n",x[0]+1,y[2]+1,sum[0]);printf("%d %d %d\n",x[3]-sum[3]+2,y[3]-sum[3]+2,sum[3]);
    }
    else if(sum[0]==sum[1]&&sum[0]!=sum[2]&&sum[0]==sum[3])
    {
        printf("%d %d %d\n",x[0]+1,y[0]-sum[0]+2,sum[0]);printf("%d %d %d\n",x[2]-sum[2]+2,y[2]+1,sum[2]);
    }
    else if(sum[0]!=sum[1]&&sum[0]==sum[2]&&sum[0]==sum[3])
    {
        printf("%d %d %d\n",x[0]+1,y[2]+1,sum[0]);printf("%d %d %d\n",x[1]-sum[1]+2,y[1]-sum[1]+2,sum[1]);
    }
    else if(sum[1]==sum[2]&&sum[1]==sum[3]&&sum[1]!=sum[0])
    {
        printf("%d %d %d\n",x[0]+1,y[0]-sum[0]+2,sum[0]);printf("%d %d %d\n",x[2]-sum[1]+2,y[2]+1,sum[1]);
    }
    else if(sum[0]!=sum[1]&&sum[2]!=sum[3]&&(((sum[2]==sum[0]||sum[2]==sum[1])&&(sum[3]!=sum[0]&&sum[3]!=sum[1]))||((sum[3]==sum[0]||sum[3]==sum[1])&&(sum[2]!=sum[0]&&sum[2]!=sum[1]))))
    {
        if(sum[0]<sum[1])
        {
            printf("%d %d %d\n",x[0]+1,y[0]-sum[0]+2,sum[0]);
            if(sum[2]<sum[3]) printf("%d %d %d\n",x[2]-sum[2]+2,y[2]+1,sum[2]);
            else printf("%d %d %d\n",x[3]-sum[3]+2,y[3]+1,sum[3]);
        }
        else
        {
            printf("%d %d %d\n",x[1]-sum[1]+2,y[1]-sum[1]+2,sum[1]);
            if(sum[2]<sum[3]) printf("%d %d %d\n",x[2]-sum[2]+2,y[2]+1,sum[2]);
            else printf("%d %d %d\n",x[3]-sum[3]+2,y[3]+1,sum[3]);
        }
    }
    else { printf("%d %d %d\n",x[0]+1,y[0]-sum[0]+2,sum[0]);printf("%d %d %d\n",x[1]-sum[1]+2,y[1]-sum[1]+2,sum[1]);}
    return 0;
}
