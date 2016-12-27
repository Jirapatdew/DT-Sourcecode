#include <stdio.h>

using namespace std;

char bi(int be,int end,int p,int val)
{
    int mid=(be+end)/2;
    if(mid==val)
    {
        if(p==0) return 'D';
        else return 'U';
    }
    else if(val<mid) return bi(be,mid-1,0,val);
    else return bi(mid+1,end,1,val);

}
int main()
{
    int f,c,p2=1;
    scanf("%d%d",&f,&c);
    for(int i=0;i<f;i++) p2*=2;
    printf("%c",bi(1,p2-1,0,c));
    printf("%c",bi(1,p2-1,0,c+1));
    printf("%c",bi(1,p2-1,0,c+2));
    return 0;
}
