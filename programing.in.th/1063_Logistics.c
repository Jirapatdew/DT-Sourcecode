#include <stdio.h>
#include <stdlib.h>

int chk[30]= {0};
typedef struct dt
{
    char a;
    char b;
    double c;
} dt;
int compare(const void* a,const void* b)
{
    double aa=*(double*)a;
    double bb=*(double*)b;
    if(aa>bb) return 1;
    else return -1;
}
int main()
{
    int n,i,j;
    int p,x,y;
    int link[30]= {0};
    int used[30]= {0};
    double ans=0,sum=0;
    double car[30]= {0};
    int num= {0};
    int t=-1;
    int st=0;
    int d=0;

    used[0]=1;
    link[27]=-1;
    dt data[280]= {'\0'};
    scanf("%d",&n);
    scanf("\n");
    for(i=0; i<n; i++)
    {
        scanf(" %c %c %lf",&data[i].a,&data[i].b,&data[i].c);
        x=data[i].a-'a'+1;
        y=data[i].b-'a'+1;
        if(data[i].a=='X') x=0;
        else if(data[i].b=='X') y=0;
        else if(data[i].a=='Y') x=27;
        else if(data[i].b=='Y') y=27;

        if(link[x]==0&&used[y]==0)
        {
            link[x]=y;
            used[y]=1;
            t++;
        }
        else if(link[y]==0&&used[x]==0)
        {
            link[y]=x;
            used[x]=1;
            t++;
        }
    }
    for(i=0; i<=t; i++)
    {
            if(link[st]==27)
            {
                d=1;
                break;
            }
            st=link[st];
    }
    st=0;
    if(d==1)
    {
        for(i=0; i<=t; i++)
        {
            for(j=0; j<n; j++)
            {
                x=data[j].a-'a'+1;
                y=data[j].b-'a'+1;
                if(data[j].a=='X') x=0;
                else if(data[j].b=='X') y=0;
                else if(data[j].a=='Y') x=27;
                else if(data[j].b=='Y') y=27;

                if((x==st&&y==link[st])||(y==st&&x==link[st]))
                {
                    car[num]=data[j].c;
                    num++;
                }
            }
            qsort(car,num,sizeof(double),compare);
            if(num%2==0)
            {
                ans=(car[num/2]+car[(num/2)-1])/2;
            }
            else
            {
                ans=car[num/2];
            }
            if(st==0) printf("X ");
            else printf("%c ",st+'a'-1);
            if(link[st]==27) printf("Y ");
            else printf("%c ",link[st]+'a'-1);
            printf("%.1lf\n",ans);
            sum+=ans;
            st=link[st];
            num=0;
        }
        printf("%.1lf\n",sum);
    }
    else printf("broken\n");
    return 0;
}
