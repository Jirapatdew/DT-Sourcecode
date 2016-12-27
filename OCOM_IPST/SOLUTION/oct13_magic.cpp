#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

struct dt // เก็บค่า  w,v,d,x ของประเภทที่ 2,3
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

struct hat // เก็บค่า w,v ของทุกตัว
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

    struct dt tmp1(0,0,0,0);// ใช้ในการหา d ที่เท่ากับ t(time) ตอนนั้น
    struct hat tmp2(0,0);//ใช้ในการหา w ที่ต้องการดำเนินการ

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
                x=0;// เพราะ x>0 จึงใช้ในการเช็คว่าเป็นประเภทไหน
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
            t++;//เพิ่มเวลา
        }
        else
        {
            if(magic.size()==0) {t++;printf("0\n");continue;}////**** t++ ห้ามลืม
            del=magic.begin();
            printf("%d\n",del->v);
            magic.erase(del); //ลบตัวแรก
            t++;
        }

        tmp1.d=t;//เก็บค่า t เพื่อหา d ที่เท่ากันใน time
        lo=time.lower_bound(tmp1);
        up=time.upper_bound(tmp1);
        while(lo!=up) //ทำตัวที่ d==t ทั้งหมด ถ้าไม่เจอจะไม่ทำเพราะ lo==up
        {
            tmp2.w=lo->w;//เก็บค่า w เพื่อหา w ที่เท่ากันใน magic
            del=magic.find(tmp2);//เก็บตำแหน่งที่เจอ
            if(lo->x==0) //ถ้าเป็นประเภท 2
            {
                if(del!=magic.end()) //ถ้าเจอ
                {
                    magic.erase(del); //ลบ
                }
            }
            else
            {
                if(del!=magic.end()) //ถ้าเจอ
                {
                    tmp2.w=lo->x;//set ค่า w ใหม่
                    tmp2.v=del->v;//เก็บ่คา v
                    magic.erase(del);//ลบตัวเดิม
                    magic.insert(tmp2);// เพิ่มตัวใหม่
                }
            }
            lo++;//ตัวถัดไป
        }
    }
    return 0;
}
