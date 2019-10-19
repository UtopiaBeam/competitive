#include<cstdio>
#define max(a,b) a>b? a:b
#define ans(a) a>0? a:0
int n,a[100005],mx=-1,t;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i--){
        t=ans(mx-a[i]+1);
        mx=max(mx,a[i]);
        a[i]=t;
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
