#include<cstdio>
int n,k,a[1005],max=0;
int bs(int s,int e){
    if(s==e)    return s;
    int sum=0,cnt=1,m=(s+e)/2;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>m)  sum=a[i],cnt++;
    }
    if(cnt<=k)      return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        max=(max>=a[i])*max+(max<a[i])*a[i];
    }
    printf("%d\n",bs(max,1<<30));
    return 0;
}
