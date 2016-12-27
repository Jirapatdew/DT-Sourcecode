#include <stdio.h>
#include <stdlib.h>
#define S -1
#define P -2
#define T -3
int num=0,sum=0,p1,p2;
int map[70][70];
int chk[5000];
int w,l;

int water(int x,int y)
{
    map[x][y]=num;
    if(x-1>=0&&map[x-1][y]==P)   water(x-1,y);
    if(y-1>=0&&map[x][y-1]==P)   water(x,y-1);
    if(map[x][y+1]==P) water(x,y+1);
    if(map[x+1][y]==P) water(x+1,y);
    return 0;
}
int check(int x,int y)
{
    if(map[x][y]==S) return 0;
    if(map[x][y]==T) return 1;
    if(chk[map[x][y]]==0) {chk[map[x][y]]=1;sum++;p2++;}
    return 0;
}
int main()
{
    int i,j,a,b,k;
    char input[70][70];
    int max_a=0,max_b=0,total;
    scanf("%d%d\n",&w,&l);
    for(i=0;i<l;i++) gets(input[i]);
    for(i=0;i<w;i++)
        for(j=0;j<w;j++)
        {
            if(input[i][j]=='S') map[i][j]=S;
            if(input[i][j]=='P') map[i][j]=P;
            if(input[i][j]=='T') map[i][j]=T;
        }

    //find the pond
    for(i=0;i<l;i++)
    {
        for(j=0;j<w;j++)
        {
            if(map[i][j]==P){num++;water(i,j);}
        }
    }

   //check map
   for(i=0;i<l;i++)
    {
        for(j=0;j<w;j++)
        {
            for(b=0;b<5000;b++) chk[b]=0;
            sum=0;p1=0;
            for(a=0;i+a<l&&j+a<w;a++)
            {
                p2=0;
                for(k=i+a;k>=i;k--)
                {
                    if(check(k,j+a)) {p1=1;break;}
                }
                for(k=j+a;k>=j;k--)
                {
                    if(check(i+a,k)) {p1=1;break;}
                }
                if(p1==1) {sum-=p2;break;}
            }
            total=a*a;
            if(total>max_a) {max_a=total;max_b=sum;}
            else if(total==max_a&&sum<max_b) {max_a=total;max_b=sum;}
        }
    }
    printf("%d %d",max_a,max_b);
    return 0;
}
