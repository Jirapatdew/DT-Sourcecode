/*
TASK: Pair of four
LANG: C
AUTHOR: PeaTT~
*/
#include<stdio.h>
#define MAX_CARDS 1<<10
int NumCard;
short cards[MAX_CARDS];
short DP[MAX_CARDS][MAX_CARDS];
short MAX(short a, short b){
    return (a>b)?a:b;
}
short Check(int start, int last){
    return (cards[start]==cards[last])? 1 : 0;
}
int main(){
    int i,j, k;
    char data;
    scanf("%d",&NumCard);
    for(j=0;j<=NumCard;j++)
        DP[0][j] = 0;
    for(i=1;i<=NumCard;i++){
        scanf(" %c",&data);
        cards[i] = data-'A';
        for(j=1;j<=NumCard;j++)
            DP[i][j] = 0;
    }
    for(i=2;i<NumCard;i++){
        for(j=1;j<=NumCard-i;j++){
            DP[i][j] = MAX(Check(j,j+i)+DP[i-2][j+1],MAX(DP[i-1][j],DP[i-1][j+1]));
            for(k=3;k<=i-2;k++){
                DP[i][j] = MAX(DP[i][j],DP[i-k][j]+DP[k-1][j+i-k+1]);
            }
        }
    }
    printf("%d\n",DP[NumCard-1][1]);
    return 0;
}

