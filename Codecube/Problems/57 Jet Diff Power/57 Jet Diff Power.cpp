#include<cstdio>
int n,a[200005],A,diff=0;
int abs(int x){    return x<0?  -x:x;   }
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&A);
    a[0]=a[n+1]=1<<20;
    for(int i=1;i<n;i++)
        diff+=A*abs(a[i]-a[i+1]);
    for(int i=1;i<=n;i++)
        if(a[i]<a[i+1] && a[i]<a[i-1])
            diff-=A*(A/2)-(A/2)*(A/2),a[i]+=A/2;
    printf("%d\n",diff);
    return 0;
}
