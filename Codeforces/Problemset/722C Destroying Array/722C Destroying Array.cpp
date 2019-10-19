#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100002],c[100002],sumr[100002],mx=0,ans[100002];
int n,b[100002],r[100002];
int f(int x){
    if(x!=r[x])     r[x]=f(r[x]);
    return r[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",a+i);
        r[i]=i;     c[i]=-1;
    }
    c[0]=c[n+1]=-1;
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=n;i>0;i--){
        ans[i]=mx;
        sumr[b[i]]=c[b[i]]=a[b[i]];
        if(c[b[i]+1]>=0)    r[b[i]+1]=b[i],sumr[b[i]]+=sumr[b[i]+1];
        if(c[b[i]-1]>=0)    r[b[i]]=f(b[i]-1),sumr[f(b[i]-1)]+=sumr[b[i]];
        mx=max(mx,sumr[f(b[i])]);
    }
    for(int i=1;i<=n;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
