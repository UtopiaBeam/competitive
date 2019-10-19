#include<cstdio>
#include<cstring>
int t,n,k,w[100002],c[100002],chk[100002];
bool f(int m){
    int cnt=1,sum=0;
    memset(chk,0,sizeof(chk));
    for(int i=0;i<n;i++){
        if(chk[c[i]]==cnt || sum+w[i]>m){
            cnt++;      sum=0;
        }
        sum+=w[i];
        chk[c[i]]=cnt;
    }
    return cnt<=k;
}
int bs(int s,int e){
    if(s==e){
        if(s>(int)1e8)  return -1;
        return s;
    }
    int m=(s+e)/2;
    if(f(m))    return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d %d",w+i,c+i);
        printf("%d\n",bs(1,(int)2e8));
    }
    return 0;
}
