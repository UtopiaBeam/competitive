#include<cstdio>
int n,k,a[1000005],lim=0;
int bsmax(int s,int e){
    if(s==e)    return s;
    int sum=0,cnt=1,m=(s+e+1)/2;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m)   sum=a[i],cnt++;
    }
    if(cnt<k)   return bsmax(s,m-1);
    return bsmax(m,e);
}
int bsmin(int s,int e){
    if(s==e)    return s;
    int sum=0,cnt=1,m=(s+e)/2;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m)   sum=a[i],cnt++;
    }
    if(cnt<=k)   return bsmin(s,m);
    return bsmin(m+1,e);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(lim<a[i])    lim=a[i];
    }
    if(k==1)    printf("-1\n");
    else    printf("%d\n",bsmax(lim,1e9)-bsmin(lim,1e9)+1);
    return 0;
}
