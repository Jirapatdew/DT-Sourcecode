#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
using namespace std;

char M[130][130]={{'/0'}};
int S[130][130][2]={0};//can get S @=2 $=1
int N[130][130][2]={0};//pass
//0=left 1=right
int main()
{
    int w,h;
    scanf("%d%d\n",&w,&h);
    for(int i=h;i>=1;i--) scanf("%s",M[i]+1);

    for(int j=1;j<=w;j++)
        if(M[h][j]=='#') N[h][j][0]+=N[h][j-1][0]+1;
    for(int j=w;j>=1;j--)
        if(M[h][j]=='#') N[h][j][1]+=N[h][j+1][1]+1;
    for(int j=1;j<=w;j++)
    {
        if(M[h][j]=='#') N[h][j][0]+=N[h][1][1];
        else break;
    }
    for(int j=1;j<=w;j++)///***///
    {
        if(M[h][j]=='#') N[h][j][1]=0;
        else break;
    }
    for(int j=w;j>=1;j--)
    {
        if(M[h][j]=='#') N[h][j][1]+=N[h][w][0];
        else break;
    }
    for(int j=w;j>=1;j--)///***///
    {
        if(M[h][j]=='#') N[h][j][0]=0;
        else break;
    }

    for(int j=1;j<=w;j++)//drop
    {
        if(M[h][j]=='.')
        {
            N[h][j][0]=N[h][j-1][0]+1;
            N[h][j][1]=N[h][j+1][1]+1;
            N[h-1][j][0]=N[h][j][0];
            N[h-1][j][1]=N[h][j][1];
        }
    }

    for(int i=h-1;i>=1;i--)
    {
        for(int j=1;j<=w;j++)
            if(M[i][j]=='#'&&(!(M[i][j-1]!='#')))
                N[i][j][0]+=N[i][j-1][0];
        for(int j=w;j>=1;j--)
            if(M[i][j]=='#'&&(!(M[i][j+1]!='#')))
                N[i][j][1]+=N[i][j+1][1];

        for(int j=1;j<=w;j++)
            if(M[i][j]=='#') N[i][j][0]+=N[i][1][1];
            else break;
        for(int j=1;j<=w;j++)///***///
            if(M[i][j]=='#') N[i][j][1]=0;
            else break;
        for(int j=w;j>=1;j--)
            if(M[i][j]=='#') N[i][j][1]+=N[i][w][0];
            else break;
        for(int j=w;j>=1;j--)///***///
            if(M[i][j]=='#') N[i][j][0]=0;
            else break;
        for(int j=1;j<=w;j++)//drop
        {
            if(M[i][j]!='#')//. @ #
            {
                N[i][j][0]+=N[i][j-1][0];
                N[i][j][1]+=N[i][j+1][1];
                N[i-1][j][0]=N[i][j][0];
                N[i-1][j][1]=N[i][j][1];
            }
        }
    }


    for(int j=1;j<=w;j++)
    {
        if(M[1][j]=='@') {S[1][j][0]=2;S[1][j][1]=2;}
        if(M[1][j]=='$') {S[1][j][0]=1;S[1][j][1]=1;}
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
            if(M[i][j]=='.'){S[i][j][0]=S[i-1][j][0];S[i][j][1]=S[i-1][j][1];}
        for(int j=1;j<=w;j++)
            if(S[i][j][1]==0) S[i][j][1]=S[i][j-1][1];
        for(int j=w;j>=1;j--)
            if(S[i][j][0]==0) S[i][j][0]=S[i][j+1][0];
        for(int j=1;j<=w;j++)
        {
            if(M[i][j]=='#') S[i][j][1]=S[i][1][0];
            else break;
        }
        for(int j=w;j>=1;j--)
        {
            if(M[i][j]=='#') S[i][j][0]=S[i][w][1];
            else break;
        }
    }

    int mx=0,del,tmp;
    for(int j=1;j<=w;j++) if(M[1][j]=='$') mx+=N[1][j][0]+N[1][j][1];
    printf("%d ",mx);
    tmp=mx;
    for(int i=2;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(M[i][j]=='#')
            {
                del=tmp;
                if(S[i][j][0]==1) del-=N[i][j][0];
                if(S[i][j][1]==1) del-=N[i][j][1];
                if(S[i-1][j][0]==1) del+=N[i][j][0];
                if(S[i-1][j][1]==1) del+=N[i][j][1];
                mx=MAX(mx,del);
            }
        }
    }
    printf("%d\n",mx);
//    for(int i=h;i>=1;i--)
//        {for(int j=1;j<=w;j++) printf("%d ",S[i][j][0]);printf("\n");}
//    printf("\n");
//    for(int i=h;i>=1;i--)
//        {for(int j=1;j<=w;j++) printf("%d ",S[i][j][1]);printf("\n");}
//    printf("\n");
//    for(int i=h;i>=1;i--)
//        {for(int j=1;j<=w;j++) printf("%d ",N[i][j][0]);printf("\n");}
//    printf("\n");
//    for(int i=h;i>=1;i--)
//        {for(int j=1;j<=w;j++) printf("%d ",N[i][j][1]);printf("\n");}
//    printf("\n");

    return 0;
}
