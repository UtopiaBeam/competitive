#include<stdio.h>
long long mic[100010]={1};
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=n;j>=i;j--)
            mic[j]+=mic[j-i];
    printf("%lld\n",mic[n]);
    return 0;
}
