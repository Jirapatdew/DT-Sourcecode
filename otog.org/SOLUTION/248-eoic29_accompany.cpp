#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int DAY_A[50]= {0},DAY_B[50]= {0};
int USE_A[50]= {0},USE_B[50]= {0};
int dm[45][205][45][45]= {0};
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {

        int D,M,R,KA,KB;
        cin >> D >> M >> R ;
        cin >> KA >> KB ;
        for(int i=1; i<=M; i++) scanf("%d",&DAY_A[i]);
        for(int i=1; i<=M; i++) scanf("%d",&DAY_B[i]);
        for(int i=1; i<=M; i++) scanf("%d",&USE_A[i]);
        for(int i=1; i<=M; i++) scanf("%d",&USE_B[i]);

        for(int i=1; i<=M; i++)
            for(int j=0; j<=D; j++)
                for(int k=0; k<=KA; k++)
                    for(int l=0; l<=KB; l++) dm[i][j][k][l]=0;

        dm[0][0][0][0]=1;
        for(int i=1; i<=M; i++)
        {
            for(int j=0; j<=D; j++)
            {
                for(int k=0; k<=KA; k++)
                {
                    for(int l=0; l<=KB; l++)
                    {
                        if(dm[i-1][j][k][l]==0) continue;
                        if(DAY_A[i]!=-1)
                        {
                            if(!(j+DAY_A[i]>D||k+USE_A[i]>KA))
                            {
                                dm[i][j+DAY_A[i]][k+USE_A[i]][l]=1;
                            }
                            //printf("---> %d %d %d %d\n",i,j+DAY_A[i],k+USE_A[i],l);}
                        }
                        if(DAY_B[i]!=-1)
                        {
                            if(!(j+DAY_B[i]>D||l+USE_B[i]>KB))
                            {
                                dm[i][j+DAY_B[i]][k][l+USE_B[i]]=1;
                            }
                            //printf("---> %d %d %d %d\n",i,j+DAY_B[i],k,l+USE_B[i]);}
                        }
                    }
                }
            }
        }
        int mn=2000000000;
        for(int j=0; j<=D; j++)
        {
            for(int k=0; k<=KA; k++)
            {
                for(int l=0; l<=KB; l++)
                {
                    if(dm[M][j][k][l]==1)
                        mn=min(mn,k+l);
                }
            }
        }
        if(mn!=2000000000&&R>mn) cout << R-mn << endl;
        else cout << -1 << endl;
    }
    return 0;
}

