#include<stdio.h>
long long mic[50]={1};
int main(){
    int n,i,j,a;
    scanf("%d",&n);
    a=(n*(n+1))/2;
    if(a%2){
        printf("0\n");
        return 0;
    }
    a/=2;
    for(i=1;i<=n;i++)
        for(j=a;j>=i;j--)
            mic[j]+=mic[j-i];
    printf("%lld\n",mic[a]/2);
    return 0;
}
