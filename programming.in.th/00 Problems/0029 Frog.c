#include<stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    if(y/x<1)       printf("2\n");
    else if(y%x)    printf("%d\n",y/x+1);
    else            printf("%d\n",y/x);
    return 0;
}
