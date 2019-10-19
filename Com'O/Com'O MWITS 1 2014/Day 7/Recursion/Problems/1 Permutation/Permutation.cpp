#include<stdio.h>
int a[15],b[15],n;
void permu(int now){
    if(now==n){
        for(int i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
        if(b[i]==0){
            b[i]=1,a[now]=i;
            permu(now+1);
            b[i]=0;
        }
}
int main(){
    scanf("%d",&n);
    permu(0);
    return 0;
}
