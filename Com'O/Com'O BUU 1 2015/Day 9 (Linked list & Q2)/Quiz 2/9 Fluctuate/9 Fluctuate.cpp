#include<cstdio>
#define min(a,b) a<b? a:b
#define max(a,b) a>b? a:b
int n,t,mn=1e9,mx=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(i)   mx=max(mx,t-mn);
        mn=min(mn,t);
    }
    printf("%d\n",mx);
    return 0;
}
