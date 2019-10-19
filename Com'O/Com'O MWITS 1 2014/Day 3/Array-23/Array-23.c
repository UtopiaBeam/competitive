#include<stdio.h>
int a[5][5],b[5][5];
int main(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&b[i][j]);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(a[i][j]!=b[i][j]){
                printf("A and B are not the same.\n");
                return 0;
            }
    printf("A and B are the same.\n");
    return 0;
}
