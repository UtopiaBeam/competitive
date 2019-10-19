#include<stdio.h>
#include<string.h>
int main(){
    int q,sum,i,len;
    char n[1000050];
    scanf("%d",&q);
    while(q--){
        sum=0;
        scanf(" %s",n);
        len=strlen(n);
        for(i=0;i<len;i++)
            sum+=n[i]-'0';
        printf("%d\n",sum%9);
    }
    return 0;
}
