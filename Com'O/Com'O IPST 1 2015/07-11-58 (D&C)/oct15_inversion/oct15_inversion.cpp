#include<cstdio>
int n,a[100002],t[100002];
long long ans=0;
long long merge(int s,int m,int e){
    int l=s,r=m+1;
    long long sum=0;
    for(int i=s;i<=e;i++){
        if(l>m)     t[i]=a[r++];
        else if(r>e)    t[i]=a[l++];
        else if(a[l]<=a[r]) t[i]=a[l++];
        else    t[i]=a[r++],sum+=m-l+1;
    }
    for(int i=s;i<=e;i++)   a[i]=t[i];
    return sum;
}
long long cnt(int s,int e){
    if(s>=e)     return 0;
    int m=(s+e)/2;
    return cnt(s,m)+cnt(m+1,e)+merge(s,m,e);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%lld\n",cnt(0,n-1));
    return 0;
}
