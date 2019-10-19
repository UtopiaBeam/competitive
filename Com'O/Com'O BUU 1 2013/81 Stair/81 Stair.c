#include<stdio.h>
long long mic[5010]={0,1},k;
int main(){
    int n,i,j;
    scanf("%d %lld",&n,&k);
    for(i=1;i<=n;i++)
        for(j=n;j>i;j--)
            mic[j]+=mic[j-i]%k,mic[j]%=k;
    mic[0]=mic[1]=mic[2]=0;
    for(i=0;i<=n;i++)
        printf("%lld\n",mic[i]%k);
//    printf("%lld\n",mic[n]%k);
    return 0;
}
