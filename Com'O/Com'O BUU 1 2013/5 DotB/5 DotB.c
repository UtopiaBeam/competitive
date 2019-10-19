#include<stdio.h>
int main(){
    int cnt[10],i,str,end,now;
    scanf("%d %d",&str,&end);
    for(i=0;i<10;i++)   cnt[i]=0;
    while(str<=end){
        now=str;
        while(now){
            cnt[now%10]++;
            now/=10;
        }
        str++;
    }
    for(i=0;i<10;i++)
        printf("%d %d\n",i,cnt[i]);
    return 0;
}
