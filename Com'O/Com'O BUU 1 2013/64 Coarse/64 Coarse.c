#include<stdio.h>
#include<math.h>

int main()
{
    int i,q,n,digit,j;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&n,&j);
        digit=log10(n);
        for(j=digit-1;j>0;j--)
            n+=n%(int)pow(10,j);
        printf("%d\n",n);
    }
    return 0;
}
