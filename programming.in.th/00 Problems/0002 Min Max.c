#include<stdio.h>

int main()
{
    int n,a,i,min,max;
    scanf("%d",&n);
    scanf("%d",&a);

    min=a;
    max=a;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&a);
        if(min>a)
            min=a;
        if(max<a)
            max=a;
    }
    printf("%d\n",min);
    printf("%d",max);
    return 0;
}
