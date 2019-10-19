#include<cstdio>
int n,x,y,a[1002],mn=(int)1e9,ans,mx=(int)-1e9;
int main(){
    scanf("%d %d %d",&n,&x,&y);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(mx<a[i])     mx=a[i];
    }
    if(mx<x)    mx=x;
    for(int w=mx;w<=y;w++){
        int cnt=0,sum=0;
        for(int i=0;i<n;i++){
            if(sum+a[i]>w)  cnt+=w-sum,sum=0;
            sum+=a[i];
        }
        cnt+=w-sum;
        if(mn>cnt)  mn=cnt,ans=w;
    }
    printf("%d\n",ans);
    return 0;
}
