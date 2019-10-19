#include<cstdio>
int n,a[1002],ans=0,cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(true){
        for(int i=0;i<n;i++)
            if(a[i]<=cnt)   cnt++,a[i]=1<<20;
        if(cnt==n)      break;
        ans++;
        for(int i=n-1;i>=0;i--)
            if(a[i]<=cnt)   cnt++,a[i]=1<<20;
        if(cnt==n)      break;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
