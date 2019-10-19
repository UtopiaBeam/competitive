#include<stdio.h>
int a[110];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0,in=i;i<n;i++){
        for(int j=i,Min=1<<20;j<n;j++)
            if(Min>a[j])    Min=a[j],in=j;
        int t=a[i]; a[i]=a[in]; a[in]=t;
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
