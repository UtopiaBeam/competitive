#include<stdio.h>
int a[10],v,in;
int main(){
    int i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d %d",&v,&in);
    a[in]=v;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
