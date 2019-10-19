#include<cstdio>
int n,a[5002]={1},cnt[10],len=1;
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        for(int j=0;j<len;j++)  a[j]*=i;
        for(int j=0;j<len;j++){
            if(a[j]/10 && j==len-1) len++;
            a[j+1]+=a[j]/10,a[j]%=10;
        }
    }
    for(int i=len-1;i>=0;i--){
        printf("%d",a[i]);
        cnt[a[i]]++;
    }
    for(int i=0;i<10;i++)
        printf("\n%d : %d",i,cnt[i]);
    return 0;
}
