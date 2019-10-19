#include<cstdio>
#include<cstring>
#define ll long long
ll a[200002],b[200002];
int t,n;
ll mergeCnt(int s,int m,int e){
    int l=s,r=m+1;
    ll cnt=0;
    for(int i=s;i<=e;i++){
        if(l>m)     b[i]=a[r++];
        else if(r>e)    b[i]=a[l++];
        else if(a[l]<=a[r]) b[i]=a[l++];
        else    b[i]=a[r++],cnt+=m-l+1;
    }
    for(int i=s;i<=e;i++)
        a[i]=b[i];
    return cnt;
}
ll cntInversion(int s,int e){
    if(s>=e)     return 0;
    int m=(s+e)/2;
    return cntInversion(s,m)+cntInversion(m+1,e)+mergeCnt(s,m,e);
}
int main(){
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        printf("%lld\n",cntInversion(0,n-1));
    }
    return 0;
}
