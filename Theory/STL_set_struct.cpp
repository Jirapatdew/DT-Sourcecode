#include<stdio.h>
#include<set>
using namespace std;
struct petp
{
    int n1;
    int n2;
    char c;
    bool operator < (const petp &T) const
    {
        if(n1 != T.n1)return n1 < T.n1; //เรียงจากน้อยไปมาก ทั้งค่าหน้าและหลัง
        else {
            return n2 < T.n2;
        }

        //return n1 < T.n1; //เรียงจากน้อยไปมาก
        //return n1 > T.n1; //เรียงจากมากไปน้อย
    }
    petp(int a,int b,char g)
    {
        n1 = a;
        n2 = b;
        c = g;
    }
};

int main()
{
    set<petp> WTF;
    set<petp>::iterator pt;
    int i,n;
    int x,y;
    char z;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %c",&x,&y,&z);
        WTF.insert(petp(x,y,z));
    }
    pt=WTF.begin();
    while(pt!=WTF.end())
    {
        printf("%d %d %c\n",pt->n1,pt->n2,pt->c);
        pt++;
    }
}
