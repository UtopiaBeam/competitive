#include<cstdio>
#include<algorithm>
int n,m,a[10002],mx=0;
bool chk(int k){
    int cnt=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>k)   cnt++,sum=a[i];
    }
    return (cnt<m);
}
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e+1)/2;
    if(chk(m))      return bs(s,m-1);
    return bs(m,e);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        mx=std::max(mx,a[i]);
    }
    int ans=bs(mx,2000000000);
    if(chk(ans))    printf("IMPOSSIBLE\n");
    else            printf("%d\n",ans);
    return 0;
}
