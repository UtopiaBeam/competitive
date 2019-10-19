#include<stdio.h>
int a[10],v;
int main(){
    int i,j;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&v);
    for(i=0;i<10;i++){
        if(a[i]==v){
           for(j=i;j<9;j++)
                a[j]=a[j+1];
           a[9]=0;
        }
    }
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
