#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,s,ms;//�ӹǹ���駷�����͡������ N� ����á������͡�� S �ӹǹ���駷�衴 M
    int h,v,m;//�ʴ���ȷҧ�ǹ͹ H(�ҡ�������)�ʴ���ȷҧ�ǵ�� V (�ҡ�������)ʴ��ӹǹ���駷�衴������� (M)
    int i,j,p,md,pa=-1;
    char ans[100]={'/0'};
    char data[10][6]={{},{},{'A','B','C'},{'D','E','F'},{'G','H','I'}
                    ,{'J','K','L'},{'M','N','O'},{'P','Q','R','S'}
                    ,{'T','U','V'},{'W','X','Y','Z'}};
    scanf("%d %d %d",&n,&s,&ms);
    md=(s==7||s==9)?4:3;
    if(s!=1)ans[++pa]=data[s][(ms-1)%md];
    p=s;
    for(i=1;i<n;i++)
    {
        scanf("%d %d %d",&h,&v,&m);
        if(h<=-1) p=p-(h*-1);
        else if(h>=1) p=p+h;
        if(v<=-1) p=p-3*(v*-1);
        else if(v>=1) p=p+3*v;
        md=(p==7||p==9)?4:3;
        if(p==1&&pa>=-1)
         {
            for(j=1;j<=m&&pa>=-1;j++)
              {
                 ans[pa--]='\0';
              }
         }
        else if(p!=1) ans[++pa]=data[p][(m-1)%md];
    }
    if(ans[0]=='\0') printf("null");
    else for(i=0;i<=pa;i++) printf("%c",ans[i]);
    return 0;
}
/*��ҡ�����ź 3 ���� ����� ź 3 ����ѡ�� ����Ѥ�Ѻ*/
