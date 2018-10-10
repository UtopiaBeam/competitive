#include<stdio.h>
int a[10];
int main(){
    for(int i=0;i<5;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1],a[j+1]=t;
                for(int k=0;k<5;k++)
                    printf("%d ",a[k]);
                printf("\n");
            }
    return 0;
}
