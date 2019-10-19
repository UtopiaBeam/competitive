#include<stdio.h>

int main()
{
    int n,i,j,a1,a2,a3,a4,a5,a6;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6);
        a1+=a2/a3,a2%=a3;   a4+=a5/a6,a5%=a6;
        if(a1==a4)
        {
            if((a2*a6)==(a3*a5))
                printf("0\n");
            else if((a2*a6)>(a3*a5))
                printf("1\n");
            else
                printf("2\n");
        }
        else if(a1>a4)
            printf("1\n");
        else
            printf("2\n");
    }

    return 0;
}
