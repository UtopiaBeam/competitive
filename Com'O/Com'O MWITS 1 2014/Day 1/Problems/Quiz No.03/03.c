#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<50)    printf("F\n");
    else if(n<60)   printf("D\n");
    else if(n<70)   printf("C\n");
    else if(n<80)   printf("B\n");
    else        printf("A\n");
    return 0;
}
