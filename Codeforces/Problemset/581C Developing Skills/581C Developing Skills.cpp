#include<cstdio>
int n,k,t,a[10],ans=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        ans+=t/10;
        a[t%10]++;
    }
    for(int i=9;i>=0 && k>0;i--){
        if(k>=a[i]*(10-i))     ans+=a[i],k-=a[i]*(10-i);
        else        ans+=k/(a[i]*(10-i)),k%=(10-i);
    }
    printf("%d\n",ans+k/10<=10*n? ans+k/10:10*n);
    return 0;
}
