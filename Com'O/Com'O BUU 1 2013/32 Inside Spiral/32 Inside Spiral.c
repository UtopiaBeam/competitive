#include<stdio.h>

int main()
{
    int m,n,move;
    scanf("%d %d",&n,&m);
    if(n<=m)
        move=2*n-2;
    else
        move=2*m-1;

    printf("%d",move);
    return 0;
}
