#include<cstdio>
#include<cstring>
int n,t,a[505],len;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        a[0]=1,len=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<len;j++)
                a[j]*=i;
            for(int j=0;j<len;j++)
                if(a[j]>9){
                    a[j+1]+=a[j]/10,a[j]%=10;
                    if(j>=len-1)    len++;
                }
        }
        for(int i=len-1;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
