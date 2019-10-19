#include<stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",i+j-1);
        }
            printf("\n");
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if((i+j-1)%n==0)
                printf("%d ",n);
            else
            printf("%d ",(i+j-1)%n);
        }
            printf("\n");
    }
    return 0;
}
