#include<stdio.h>
int a[1000010],sum[1000010];
int main(){
    int n,q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        sum[i]=a[i+1]-a[i];
        if(sum[i]<0)    sum[i]=0;
    }
    for(int i=2;i<n;i++)
        sum[i]+=sum[i-1];
    scanf("%d",&q);
    while(q--){
        int str,end;
        scanf("%d %d",&str,&end);
        printf("%d\n",sum[end-1]-sum[str-1]);
    }
    return 0;
}
