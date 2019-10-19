#include<stdio.h>
int num[800]={1},n,len=1,cnt[10];
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        for(int j=0;j<len;j++)
            num[j]*=i;
        for(int j=0;j<len;j++)
            if(num[j]>9){
                num[j+1]+=num[j]/10,num[j]%=10;
                if(j==len-1)    len++;
            }
    }
    for(int i=len-1;i>=0;i--)
        printf("%d",num[i]);
    printf("\n");
    for(int i=0;i<len;i++)
        cnt[num[i]]++;
    for(int i=0;i<10;i++)
        printf("%d : %d\n",i,cnt[i]);
    return 0;
}
