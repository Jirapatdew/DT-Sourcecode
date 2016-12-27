#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
//#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
//#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))

using namespace std;

int M[10][10]={0};//0=A 1=B 2=C 3=a 4=b 5=c
int chk[10][10][10]={0};
int p[10][10][10]={0};
int a,b,c;
int d,e,f;
int pri=0;
struct dt
{
    int x,y,z;
    dt(int _x,int _y,int _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }
};
queue<dt> Q;
int print(int x,int y,int z,int num)
{
    if(x==d&&y==e&&z==f)
    {
        printf("%d ",num);
        return 0;
    }
    int tmp[3],i=chk[x][y][z];
    tmp[0]=x-M[i][3]+M[i][0];
    tmp[1]=y-M[i][4]+M[i][1];
    tmp[2]=z-M[i][5]+M[i][2];
    print(tmp[0],tmp[1],tmp[2],num+1);
    if(i<3)printf("%c",i+'A');
    else printf("%c",i-3+'a');

}
int BFS()
{
    int x,y,z;
    while(!Q.empty())
    {
        x=Q.front().x;
        y=Q.front().y;
        z=Q.front().z;
        Q.pop();
        if(x==a&&y==b&&z==c)
        {
            print(x,y,z,0);
            printf("\n");//print chk
            pri=1;
            return 0;
        }
        int tmp[3];
        for(int i=0;i<6;i++)
        {
            if(x<M[i][0]||y<M[i][1]||z<M[i][2]) continue;
            tmp[0]=x-M[i][0]+M[i][3];
            tmp[1]=y-M[i][1]+M[i][4];
            tmp[2]=z-M[i][2]+M[i][5];
            if(tmp[0]>9||tmp[1]>9||tmp[2]>9) continue;
            if(chk[tmp[0]][tmp[1]][tmp[2]]==-1)
            {
                chk[tmp[0]][tmp[1]][tmp[2]]=i;
                Q.push(dt(tmp[0],tmp[1],tmp[2]));
            }
        }
    }



}
int main()
{
    int n;
    M[0][0]=M[3][3]=1;
    M[1][1]=M[4][4]=1;
    M[2][2]=M[5][5]=1;
    scanf("%d%d%d",&M[0][3],&M[0][4],&M[0][5]);
    M[3][0]=M[0][3];M[3][1]=M[0][4];M[3][2]=M[0][5];
    scanf("%d%d%d",&M[1][3],&M[1][4],&M[1][5]);
    M[4][0]=M[1][3];M[4][1]=M[1][4];M[4][2]=M[1][5];
    scanf("%d%d%d",&M[2][3],&M[2][4],&M[2][5]);
    M[5][0]=M[2][3];M[5][1]=M[2][4];M[5][2]=M[2][5];

//    for(int i=0;i<6;i++)
//    {
//        for(int j=0;j<6;j++) printf("%d ",M[i][j]);
//        printf("\n");
//    }

    scanf("%d",&n);
    while(n>0)
    {
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<10;k++) chk[i][j][k]=-1;
        scanf("%d%d%d",&d,&e,&f);
        while(!Q.empty()) Q.pop();
        Q.push(dt(d,e,f));
        scanf("%d%d%d",&a,&b,&c);
        pri=0;
        BFS();
        if(pri==0) printf("NO SOLUTION\n");
        n--;
    }
    return 0;
}
