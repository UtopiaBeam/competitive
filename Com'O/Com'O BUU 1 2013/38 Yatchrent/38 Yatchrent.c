#include<stdio.h>

int main()
{
    int n,sum=1,i,k,total=0;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        sum=1;
        printf("1");
        for(k=2;k<=i;k++)
        {
            printf(" + %d",k);
            sum+=k;
        }
        printf(" = %d\n",sum);
        total+=sum;
    }
    printf("sum = %d",total);
    return 0;
}
