#include<stdio.h>

int main()
{
    int score[10][10],i,j,sum[10]={0},max=0,index=0;

    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&score[i][j]);
            sum[i]+=score[i][j];
        }
    }
    for(i=0;i<5;i++)
    {
        if(max<sum[i])
        {
            max=sum[i];
            index=i+1;
        }
    }

    printf("%d %d",index,max);

    return 0;
}
