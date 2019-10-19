#include<stdio.h>

int main()
{
    long long i,j,k,run,cnt,t;
    int max=0;
    scanf("%lld %lld",&i,&j);

    if(i>j)
        t=i,i=j,j=t;

    for(k=i;k<=j;k++)
    {
        run=k;
        cnt=0;
        while(1)
        {
            cnt++;
            if(run==0 || run==1)
                break;
            else if(run%2)
                run=run*3+1;
            else
                run=run/2;
        }
        if(max<cnt)
            max=cnt;
    }
    printf("%d\n",max);
    return 0;
}
