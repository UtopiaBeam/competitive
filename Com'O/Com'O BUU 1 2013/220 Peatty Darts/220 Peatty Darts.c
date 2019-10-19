#include<stdio.h>

int point(int i,int j)
{
    if(i*i+j*j<=4)
        return 5;
    if(i*i+j*j<=16)
        return 4;
    if(i*i+j*j<=36)
        return 3;
    if(i*i+j*j<=64)
        return 2;
    if(i*i+j*j<=100)
        return 1;
    return 0;
}

int main()
{
    int q,i,x,y,sum=0;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&x,&y);
        sum+=point(x,y);
    }
    printf("%d\n",sum);
}
