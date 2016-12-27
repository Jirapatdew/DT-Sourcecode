#include <cstdio>
#include <list>

using namespace std;

list<int> dew;
list<int>::iterator pt;

int main()
{
    int op,tmp;
    while(1)
    {
        scanf("%d",&op);
        if(op==0) break; //end program
        else if(op==1) //push-back
        {
            scanf("%d",&tmp);
            dew.push_back(tmp);
        }
        else if(op==3) //show
        {
            if(dew.empty())//if(dew.empty()==true)
            {
                printf("EMPTY\n");
            }
            else
            {
                pt=dew.begin();
                while(pt!=dew.end())
                {
                    printf("%d ",*pt);
                    pt++;
                }
                printf("\n");
            }
        }
        else if(op==-1) //pop-front
        {
            if(!dew.empty()) dew.pop_front(); //if(dew.empty()==false)
            //else printf("EMPTY\n");
        }
    }
    return 0;
}
