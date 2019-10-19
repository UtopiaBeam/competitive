#include<stdio.h>
int a[30],b[30],n,k;
void permu(int now){
    if(now==k){
        for(int i=0;i<k;i++)
            printf("%c",a[i]+'a');
        printf("\n");
        return ;
    }
    for(int i=0;i<n;i++)
        if(b[i]==0){
            if(now>0 && i<=a[now-1])    continue;
            b[i]=1,a[now]=i;
            permu(now+1);
            b[i]=0;
        }
}
int main(){
    scanf("%d %d",&n,&k);
    permu(0);
    return 0;
}
