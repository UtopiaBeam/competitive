#include<stdio.h>
int a[5][5],sumx[5];
int main(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
            sumx[i]+=a[i][j];
        }
    for(i=0;i<3;i++)
        printf("%d\n",sumx[i]);
    return 0;
}
