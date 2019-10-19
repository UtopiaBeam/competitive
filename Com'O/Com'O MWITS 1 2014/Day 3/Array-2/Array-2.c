#include<stdio.h>
int a[10],v;
int main(){
    int i;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&v);
    for(i=0;i<10;i++)
        if(v==a[i]){
            printf("V is in the array\n");
            return 0;
        }
    printf("V is not in the array\n");
    return 0;
}
