#include<stdio.h>

int main()
{
    int a,b,c,n,i,check;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d",&n);

    int jump[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&jump[i]);
        jump[i];
        if(jump[i]<a)
            printf("no\n");
        else if(jump[0]==a)
            printf("yes\n");
        else
        {
            check=(jump[i]-a)%(b+c);
            if(check<=b)
                printf("yes\n");
            else if(check>b && check<b+c)
                printf("no\n");
        }
    }

    return 0;
}
