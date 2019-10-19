#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10],i,t,cnt=0;

    for(i=0;i<4;i++)
        scanf("%d",&a[i]);

    for(i=0;i<4;i++)
        printf("%d\t",a[i]);
    printf("\n");

    while(a[0]||a[1]||a[2]||a[3])
    {
        t=a[0],a[0]=abs(a[0]-a[1]),a[1]=abs(a[1]-a[2]),a[2]=abs(a[2]-a[3]),a[3]=abs(a[3]-t);
        printf("%d\t%d\t%d\t%d\n",a[0],a[1],a[2],a[3]);
        cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}
