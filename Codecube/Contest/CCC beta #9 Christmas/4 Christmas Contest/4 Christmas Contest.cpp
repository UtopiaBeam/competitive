#include<cstdio>
#include<algorithm>
int n,m,mx=0,t;
long long ans=0,a[32],b[32];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        int dg=0;
        while(t){
            a[dg++]+=t&1;
            t>>=1;
        }
        mx=std::max(mx,dg);
    }
    scanf("%d",&m);
    for(int j=0;j<m;j++){
        scanf("%d",&t);
        int dg=0;
        while(t){
            b[dg++]+=t&1;
            t>>=1;
        }
        mx=std::max(mx,dg);
    }
    for(int i=mx-1;i>=0;i--){
        ans*=2;
        ans+=a[i]*(m-b[i])+(n-a[i])*b[i];
    }
    printf("%lld\n",ans);
    return 0;
}
