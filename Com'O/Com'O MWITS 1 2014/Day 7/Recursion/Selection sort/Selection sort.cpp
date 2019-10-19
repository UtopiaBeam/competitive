#include<stdio.h>
int a[110];
void ssort(int n){
    if(n==0)    return ;
    int max=-1<<20,in=0;
    for(int i=0;i<=n;i++)
        if(max<a[i])    max=a[i],in=i;
    int t=a[n]; a[n]=a[in],a[in]=t;
    ssort(n-1);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ssort(n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
