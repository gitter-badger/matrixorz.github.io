#include <stdio.h>
#include <stdlib.h>

void trackPrint(int m,int *coinTrack)
{
    if(m==0)
        return;
    else
    {
        printf("%d",coinTrack[m]);
        trackPrint(m-coinTrack[m],coinTrack);
    }
}

void makeChange(int coinValue[],int money,int coinTypes,int *coinUsed,int *coinTrack)
{
    int i,j;
    int minCoins;
    int lastIn;

    for(i=1;i<=money;i++)
    {
        minCoins=9999999;
        lastIn=0;

        for(j=0;j<coinTypes;j++)
        {
            if (coinValue[j]>i)
                continue;
            if(coinUsed[i-coinValue[j]]+1<minCoins)
            {
                minCoins=coinUsed[i-coinValue[j]]+1;
                lastIn=j;
            }
        }
        coinUsed[i]=minCoins;
        coinTrack[i]=coinValue[lastIn];

        printf("面值为%d所需要的最小硬币数: %d,",i,coinUsed[i]);
        printf(" 硬币为：");
        trackPrint(i,coinTrack);
        printf("\n");
    }
}


int main()
{
    int i;
    int coinValue[]={25,21,10,5,1};
    int money=50;
    int coinTypes;

    int* coinUsed=(int *)malloc((money+1)*sizeof(int));
    int *coinTrack=(int *)malloc(sizeof(money+1)*sizeof(int));

    for(i=0;i<=money;i++)
    {
        coinUsed[i]=0;
        coinTrack[i]=0;
    }
    coinTypes=sizeof(coinValue)/sizeof(*coinValue);
    makeChange(coinValue,money,coinTypes,coinUsed,coinTrack);

    free(coinUsed);
    free(coinTrack);
    return 0;
}
