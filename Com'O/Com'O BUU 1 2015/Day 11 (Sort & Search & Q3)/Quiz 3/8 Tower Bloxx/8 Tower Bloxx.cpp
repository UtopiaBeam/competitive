#include<cstdio>
int n,q,a[102]={0,1,2};
int main(){
    for(int i=3;i<=100;i++) a[i]=a[i-1]+a[i-2],a[i]%=(int)(1e7+19);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
