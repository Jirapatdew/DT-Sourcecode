#include <stdio.h>
#include <stdlib.h>

int map[1050][1050]={0};
int divide(int stx,int spx,int sty,int spy,int x,int y)
{
    int midx=(stx+spx)/2,midy=(sty+spy)/2;
    map[y][x]=-1;
    if(spx-stx<=1) return 0;
    if(stx<=x&&sty<=y&&x<=midx&&y<=midy) //q2
    {
        printf("0 %d %d\n",midx,midy);
        divide(midx+1,spx,sty,midy,midx+1,midy);//q1
        divide(stx,midx,sty,midy,x,y);//q2
        divide(stx,midx,midy+1,spy,midx,midy+1);//q3
        divide(midx+1,spx,midy+1,spy,midx+1,midy+1);//q4
    }
    if(stx<=x&&midy<y&&x<=midx&&y<=spy) //q3
    {
        printf("2 %d %d\n",midx,midy);
        divide(midx+1,spx,sty,midy,midx+1,midy);//q1
        divide(stx,midx,sty,midy,midx,midy);//q2
        divide(stx,midx,midy+1,spy,x,y);//q3
        divide(midx+1,spx,midy+1,spy,midx+1,midy+1);//q4
    }
    if(midx<x&&sty<=y&&x<=spx&&y<=midy) //q1
    {
        printf("1 %d %d\n",midx,midy);
        divide(midx+1,spx,sty,midy,x,y);//q1
        divide(stx,midx,sty,midy,midx,midy);//q2
        divide(stx,midx,midy+1,spy,midx,midy+1);//q3
        divide(midx+1,spx,midy+1,spy,midx+1,midy+1);//q4
    }
    if(midx<x&&midy<y&&x<=spx&&y<=spy) //q4
    {
        printf("3 %d %d\n",midx,midy);
        divide(midx+1,spx,sty,midy,midx+1,midy);//q1
        divide(stx,midx,sty,midy,midx,midy);//q2
        divide(stx,midx,midy+1,spy,midx,midy+1);//q3
        divide(midx+1,spx,midy+1,spy,x,y);//q4
    }
}
int main()
{
    int l,x,y,i,j;
    scanf("%d%d%d",&l,&x,&y);
    printf("%d\n",l*l/3);
    divide(0,l-1,0,l-1,x,y);
    for(i=0;i<l-1;i+=2)
    {
        for(j=0;j<l-1;j+=2)
        {
            if(map[i][j]==-1) printf("0 ");
            else if(map[i][j+1]==-1) printf("1 ");
            else if(map[i+1][j]==-1) printf("2 ");
            else if(map[i+1][j+1]==-1) printf("3 ");
            printf("%d %d\n",j,i);
        }
    }
    //map[x][y]=-1;
    return 0;
}
