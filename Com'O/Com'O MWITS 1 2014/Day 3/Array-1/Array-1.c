#include<stdio.h>
int a[10];
int main(){
    int i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<10;i++)
        if(a[i]>=10)    printf("%d ",a[i]);
    printf("\n");
    return 0;
}
