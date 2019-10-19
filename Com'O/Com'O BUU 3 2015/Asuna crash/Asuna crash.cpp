#include<cstdio>
#include<cstring>
int q,n,k,f[15]={1},a[15];
int main(){
    for(int i=1;i<12;i++)
        f[i]=f[i-1]*i;
    scanf("%d",&q);
    while(q--){
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&k);
        for(int i=n-1;i>=0;i--){
            int cnt=k/f[i]+(k%f[i]!=0);
            for(int j=1;j<=n;j++){
                if(a[j]==0)     cnt--;
                if(cnt<=0){
                    a[j]=1;
                    printf("%d ",j);
                    break;
                }
            }
            k=(k+f[i]-1)%f[i]+1;
        }
        printf("\n");
    }
    return 0;
}
