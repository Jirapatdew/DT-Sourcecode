#include <stdio.h>
#include <stdlib.h>

//0=ไม่มี ,1 ดำ ,2 ขาว
int map[10][10]={0};
int chk(int x,int y,int s)
{
    int i,j,k,l,p=0;
    map[x][y]=s;
    for(i=x-1;i>=0;i--) //N
    {
        if(map[i][y]==0) break;
        else if(map[i][y]==s)
        {
            for(j=i+1;j<x;j++) map[j][y]=s;
            p=1;
            break;
        }
    }

    for(i=x+1;i<=8;i++) //S
    {
        if(map[i][y]==0) break;
        else if(map[i][y]==s)
        {
            for(j=i-1;j>x;j--) map[j][y]=s;
            p=1;
            break;
        }
    }

    for(i=y+1;i<=8;i++) //E
    {
        if(map[x][i]==0) break;
        else if(map[x][i]==s)
        {
            for(j=i-1;j>y;j--) map[x][j]=s;
            p=1;
            break;
        }
    }

    for(i=y-1;i>=0;i--) //W
    {
        if(map[x][i]==0) break;
        else if(map[x][i]==s)
        {
            for(j=i+1;j<y;j++) map[x][j]=s;
            p=1;
            break;
        }
    }

    for(i=x-1,j=y-1;i>=0&&j>=0;i--,j--) //NW
    {
        if(map[i][j]==0) break;
        else if(map[i][j]==s)
        {
            for(k=i+1,l=j+1;k<x&&l<y;k++,l++) map[k][l]=s;
            p=1;
            break;
        }
    }

    for(i=x+1,j=y+1;i<=8&&j<=8;i++,j++) //SE
    {
        if(map[i][j]==0) break;
        else if(map[i][j]==s)
        {
            for(k=i-1,l=j-1;k>x&&l>y;k--,l--) map[k][l]=s;
            p=1;
            break;
        }
    }

    for(i=x-1,j=y+1;i>=0&&j<=8;i--,j++) //NE
    {
        if(map[i][j]==0) break;
        else if(map[i][j]==s)
        {
            for(k=i+1,l=j-1;k<x&&l>y;k++,l--) map[k][l]=s;
            p=1;
            break;
        }
    }

    for(i=x+1,j=y-1;i<=8&&j>=0;i++,j--) //SW
    {
        if(map[i][j]==0) break;
        else if(map[i][j]==s)
        {
            for(k=i-1,l=j+1;k>x&&l<y;k--,l++) map[k][l]=s;
            p=1;
            break;
        }
    }
    return p;
}
int main()
{
    int n,i,j,t;
    int x,y;
    char ch[3];
    scanf("%d\n",&n);
    map[4][4]=2;
    map[5][5]=2;
    map[5][4]=1;
    map[4][5]=1;
    t=1;
    for(i=0;i<n;i++)
    {
        scanf("%s",ch);
        scanf("%d",&x);
        y=ch[0]-'a'+1;
        //if(i%2==0) chk(x,y,1);
        //else chk(x,y,2);
        if(!chk(x,y,t)) {t=3-t;chk(x,y,t);}
        t=3-t;
    }
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(map[i][j]==0) printf(".");
            else if(map[i][j]==1) printf("X");
            else printf("O");
        }
        printf("\n");
    }
    return 0;
}
