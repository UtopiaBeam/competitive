#include<cstdio>
int n,m,a[105],t,ans=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int mx=0,in=0;
        for(int j=0;j<n;j++){
            scanf("%d",&t);
            if(mx<t)    mx=t,in=j;
        }
        if(a[ans]<++a[in])  ans=in;
        else if(a[ans]==a[in] && in<ans)    ans=in;
    }
    printf("%d\n",ans+1);
    return 0;
}
