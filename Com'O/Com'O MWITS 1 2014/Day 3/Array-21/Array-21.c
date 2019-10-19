#include<stdio.h>
int a[5][5],max[5]={-1<<20,-1<<20,-1<<20};
int main(){
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]>max[j])  max[j]=a[i][j];
        }
    for(i=0;i<3;i++)
        printf("%d\n",max[i]);
    return 0;
}
