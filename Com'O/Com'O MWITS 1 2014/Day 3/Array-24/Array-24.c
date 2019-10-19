#include<stdio.h>
int main(){
    int a[5][5],b,i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&b);
            printf("%d ",a[i][j]+b);
        }
        printf("\n");
    }
    return 0;
}
