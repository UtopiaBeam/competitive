#include<cstdio>
int n,m,cnt=0,a[1000002],b[1000002],t;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        b[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        cnt+=(i>=b[t]);
        b[t]=(i>=b[t])*(i+a[t])+(i<b[t])*b[t];
    }
    printf("%d\n",cnt);
    return 0;
}
