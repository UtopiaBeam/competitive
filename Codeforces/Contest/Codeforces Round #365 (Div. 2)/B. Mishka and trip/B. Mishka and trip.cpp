#include<cstdio>
int n,k,b[100002],c[100002];
long long sum=0,all=0,ans=0,a[100002],t=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%I64d",&a[i]);
        all+=a[i];
    }
    for(int i=0;i<n;i++)
        ans+=a[i]*a[(i+1)%n];
    for(int i=0;i<k;i++){
        scanf("%d",&b[i]);
        b[i]--;
        ans+=a[b[i]]*(all-a[b[i]]-a[(b[i]+n-1)%n]-a[(b[i]+1)%n]);
        sum+=a[b[i]];
    }
    for(int i=1;i<k;i++)
        if(b[i]==b[i-1]+1)
            c[b[i-1]]=1;
    if(b[0]==0 && b[k-1]==n-1)
        c[n-1]=1;
    for(int i=0;i<k;i++)
        t+=a[b[i]]*(sum-a[b[i]]);
    for(int i=0;i<n;i++)
        ans+=c[i]*(a[i]*a[(i+1)%n]);
    printf("%I64d\n",ans-t/2);
    return 0;
}
