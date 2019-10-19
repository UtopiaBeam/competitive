#include<cstdio>
long long ans=1;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        ans*=4;
    printf("%lld\n",ans);
    return 0;
}
