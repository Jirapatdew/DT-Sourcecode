#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

struct dt // �纤��  w,v,d,x �ͧ��������� 2,3
{
    int w,v,d,x;
    bool operator < (const dt &T) const
    {
        return d<T.d;
    }
    dt(int a,int b,int c,int e)
    {
        w=a;v=b;d=c;x=e;
    }
};

struct hat // �纤�� w,v �ͧ�ء���
{
  int w,v;
  bool operator < (const hat &T) const
  {
      return w<T.w;
  }
  hat(int a,int b)
  {
      w=a;v=b;
  }
};
multiset<dt> time;
multiset<hat> magic;
multiset<dt>::iterator up,lo;
multiset<hat>::iterator del;
int main()
{
    int n,m;
    int i,k;
    int T,c;
    int w,v,d,x;
    int t=0;//time

    struct dt tmp1(0,0,0,0);// ��㹡���� d �����ҡѺ t(time) �͹���
    struct hat tmp2(0,0);//��㹡���� w ����ͧ��ô��Թ���

    scanf("%d%d",&n,&m);
    k=n+m;
    for(i=0;i<k;i++)
    {
        scanf("%d",&T);
        if(T==1)
        {
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d%d",&w,&v);
                magic.insert(hat(w,v));
            }
            else
            {
                x=0;// ���� x>0 �֧��㹡��������繻������˹
                if(c==2) scanf("%d%d%d",&w,&v,&d);
                else scanf("%d%d%d%d",&w,&v,&d,&x);//x>0
                if(d==t)
                {
                    if(c==3) magic.insert(hat(x,v));
                }
                else
                {
                    time.insert(dt(w,v,d,x));
                    magic.insert(hat(w,v));
                }
            }
            t++;//��������
        }
        else
        {
            if(magic.size()==0) {t++;printf("0\n");continue;}////**** t++ �������
            del=magic.begin();
            printf("%d\n",del->v);
            magic.erase(del); //ź����á
            t++;
        }

        tmp1.d=t;//�纤�� t ������ d �����ҡѹ� time
        lo=time.lower_bound(tmp1);
        up=time.upper_bound(tmp1);
        while(lo!=up) //�ӵ�Ƿ�� d==t ������ �������ͨ��������� lo==up
        {
            tmp2.w=lo->w;//�纤�� w ������ w �����ҡѹ� magic
            del=magic.find(tmp2);//�纵��˹觷����
            if(lo->x==0) //����繻����� 2
            {
                if(del!=magic.end()) //�����
                {
                    magic.erase(del); //ź
                }
            }
            else
            {
                if(del!=magic.end()) //�����
                {
                    tmp2.w=lo->x;//set ��� w ����
                    tmp2.v=del->v;//���� v
                    magic.erase(del);//ź������
                    magic.insert(tmp2);// �����������
                }
            }
            lo++;//��ǶѴ�
        }
    }
    return 0;
}
