#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
struct list
  {
      int point;
      int weight;
      list(int a,int b)
       {
           point = a;
           weight = b;
       }
  };
struct list2
  {
     int num;
     int fix;
     bool operator < (const list2&T)const
       {
           return num<T.num;
       }
     list2(int a,int b)
       {
           fix = a;
           num = b;
       }
  };
vector< vector<list> > vec;
vector<list> ::iterator vecte;
multiset<list2> com;
multiset<list2>::iterator comte;
int maxi,maxv,i,start,stop,a,b,c,save[10001],ans=100000000;
int save2[10001];
int main()
  {
     scanf("%d %d",&maxv,&maxi);
     vec.resize(maxv+1);
     scanf("%d %d",&start,&stop);
     for(i=0;i<maxi;i++)
       {
          scanf("%d %d %d",&a,&b,&c);
          vec[a].push_back(list(b,c));
          vec[b].push_back(list(a,c));
       }
    com.insert(list2(start,0));
    while(com.size()>0)
      {
          comte = com.begin();
          for(vecte = vec[comte->fix].begin();vecte != vec[comte->fix].end();vecte++)
            {
               if(save[vecte->point]==0||save[vecte->point] > save[comte->fix] + vecte->weight)
                 {
                    save[vecte->point]  = save[comte->fix] + vecte->weight ;
                    com.insert(list2(vecte->point,save[vecte->point]));
                 }
            }
        com.erase(comte);
      }
    com.insert(list2(stop,0));
    while(com.size()>0)
      {
          comte = com.begin();
          for(vecte = vec[comte->fix].begin();vecte != vec[comte->fix].end();vecte++)
            {
               if(save2[vecte->point]==0||save2[vecte->point] > save2[comte->fix] + vecte->weight)
                 {
                    save2[vecte->point]  = save2[comte->fix] + vecte->weight ;
                    com.insert(list2(vecte->point,save2[vecte->point]));
                 }
            }
        com.erase(comte);
      }
    for(i=1;i<=maxv;i++)
      {
            if(ans>save[i]+save2[i]&&save[i]+save2[i]!=save[stop]) ans = save[i]+save2[i];
      }
    printf("%d",ans);
    return 0;
  }
