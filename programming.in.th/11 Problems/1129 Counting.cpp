#include<cstdio>
int a[5005],n,k,now=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)   a[i]=i;
    for(int i=n;i>0;i--){
        int cnt=(k-1)%i+1;
        while(cnt){
            now=(now%n)+1;
            if(a[now]!=0)   cnt--;
        }
        printf("%d\n",a[now]);
        a[now]=0;
    }
    return 0;
}
