#include<cstdio>
int a[5005],n,t,cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        a[t]=1;
    }
    for(int i=1;i<=n;i++)
        cnt+=a[i];
    printf("%d\n",n-cnt);
    return 0;
}
