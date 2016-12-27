/*
TASK: Chest
LANG: C
AUTHOR: PeaTT~
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_MULTIPLY 200000
#define N_PFACTOR 4
#define MAX_MULTIPLYER 10
typedef struct{
	int position,factor,n;
}Factor;
int acc[N_PFACTOR],m,n;
int pfactor[N_PFACTOR]={2,3,5,7};
Factor factors[MAX_MULTIPLY*2+1];
int cmp(const void* a, const void* b){
	Factor* aa = (Factor*)a;
	Factor* bb = (Factor*)b;
	return (aa->position) - (bb->position);
}
int main(){
	int mm,s,f,i,j=0,countMax,nrange=0,x;
	long long nfactor,maxNFactor;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
		scanf("%d %d %d",&mm,&s,&f);
		factors[j].factor = factors[j+1].factor =mm;
		factors[j].position = s;
		factors[j++].n = 1;
		factors[j].position = f+1;
		factors[j++].n = -1;
    }
    factors[m*2].position = n+1;
    qsort(factors,m*2,sizeof(Factor),cmp);
    maxNFactor = 1,countMax = 1;
    for(j=0;j<N_PFACTOR;j++)
        acc[j]=0;
    for(i=0;i<m*2;){
		do{
			x = factors[i].factor;
			j=0;
            while(x>1){
                if(x%pfactor[j]==0){
                    x=x/pfactor[j];
                    acc[j]+=factors[i].n;
                }
                else{
                    j++;
                }
            }
			i++;
		}while(factors[i].position==factors[i-1].position);
		nfactor = 1;
		for(j=0;j<4;j++)
			nfactor*=acc[j]+1;
		if(maxNFactor<nfactor){
			maxNFactor = nfactor;
			countMax = factors[i].position - factors[i-1].position;
			nrange = 1;
		}
		else if(maxNFactor==nfactor){
			countMax+=factors[i].position - factors[i-1].position;
			nrange++;
		}
    }
    printf("%lld %d\n",maxNFactor,countMax);
    return 0;
}
