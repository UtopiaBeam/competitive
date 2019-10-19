#include<stdio.h>
#include<string.h>
long long a[3000000],sum=0,sum1,sum2;
int n;
long long play(int index){
    if(index>=n)    return 0;
    return a[index]+play(2*index+1)+play(2*index+2);
}
int main(){
    memset(a,-1,sizeof(a));
    int i,q,t1,t2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    printf("%lld\n",sum);
    scanf("%d",&q);
    while(q--){
        sum1=0,sum2=0;
        scanf("%d %d",&t1,&t2);
        sum1=play(t1),sum2=play(t2);
        if(sum1>sum2)   printf("%d>%d\n",t1,t2);
        else if(sum1<sum2)  printf("%d<%d\n",t1,t2);
        else    printf("%d=%d\n",t1,t2);
    }
    return 0;
}
