#include<cstdio>
long long x,y,k,a[30]={1},cnt=0,tmp;
int main(){
    scanf("%lld %lld %lld",&x,&y,&k);
    for(int i=1;i<=15;i++)
        a[i]=a[i-1]*5;
    for(int i=1;x/a[i];i++)
        cnt+=x/a[i],cnt%=k;
    tmp=cnt;
    for(long long i=x+1;i<=y;i++){
        long long t=tmp;
        for(int j=1;j<15;j++)
            if(i%a[j])      break;
            else    t++;
        tmp=t%k;
        cnt+=tmp,cnt%=k;
    }
    printf("%lld\n",cnt);
    return 0;
}
