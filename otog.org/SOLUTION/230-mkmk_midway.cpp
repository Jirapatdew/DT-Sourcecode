#include <stdio.h>
#include <algorithm>
#define MAX_N 1000015
using namespace std;

int N,X,Y,Z;
int A[MAX_N],B[MAX_N];

int main()
{
    scanf("%d%d%d%d",&N,&X,&Y,&Z);
    for(int i=0; i<N; i++) scanf("%d%d",&A[i],&B[i]);
    sort(A,A+N);
    sort(B,B+N);
    A[N]=B[N]=1000000001;
    int i=0,j=0;
    int current_milk=N*X;
    int answer=N*X;
    while(i<N||j<N)
    {
        if(A[i] <= B[j])
        {
            current_milk+=Y-X;
            i++;
        }
        else
        {
            current_milk+=Z-Y;
            j++;
        }
        if(current_milk>answer) answer=current_milk;
    }
    printf("%d",answer);
    return 0;
}
