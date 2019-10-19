#include<stdio.h>
int a[5][5];
int main(){
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<2;i++){
        for(j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
