#include<cstdio>
int a[10005],n,fac=1,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            ans+=a[j]-a[i],ans%=49999;
    for(int i=2;i<=n-2;i++)
        fac*=i,fac%=49999;
    printf("%d\n",(fac*ans)%49999);
    return 0;
}
