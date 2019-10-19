#include<cstdio>
int n,k,a[10002],mx=0;
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e+1)/2,sum=0,cnt=1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m)   sum=a[i],cnt++;
    }
    if(cnt<k)   return bs(s,m-1);
    return bs(m,e);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(mx<a[i])     mx=a[i];
    }
    int ans=bs(mx,(int)2e9),cnt=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>ans)   sum=a[i],cnt++;
    }
    if(cnt==k)      printf("%d\n",ans);
    else    printf("IMPOSSIBLE\n");
    return 0;
}
