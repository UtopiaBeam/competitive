#include<stdio.h>
#include<math.h>
int a[100010];
long long b[1010];
int main(){
    long long ans=0;
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            b[a[j]/(int)pow(10,i)%10]++;
        }
        for(j=0;j<10;j++){
            if(b[j]>1)     ans+=(b[j]*(b[j]-1))/2;
            b[j]=0;
        }
    }
    for(i=0;i<n;i++)
        b[a[i]/10]++;
    for(i=0;i<100;i++){
        if(b[i]>1)  ans-=(b[i]*(b[i]-1))/2;
        b[i]=0;
    }
    for(i=0;i<n;i++)
        b[a[i]%100]++;
    for(i=0;i<100;i++){
        if(b[i]>1)  ans-=(b[i]*(b[i]-1))/2;
        b[i]=0;
    }
    for(i=0;i<n;i++)
        b[(a[i]/100)*10+a[i]%10]++;
    for(i=0;i<100;i++){
        if(b[i]>1)  ans-=(b[i]*(b[i]-1))/2;
        b[i]=0;
    }
    for(i=0;i<n;i++)
        b[a[i]]++;
    for(i=0;i<1000;i++)
        if(b[i]>1)  ans+=(b[i]*(b[i]-1))/2;
    printf("%lld\n",ans);
    return 0;
}
