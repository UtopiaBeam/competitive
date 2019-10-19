#include<cstdio>
int n,mx=1,a[100002],t;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        a[t]=i;
    }
    t=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1])     t++;
        else        t=1;
        if(mx<t)    mx=t;
    }
    printf("%d\n",n-mx);
    return 0;
}
