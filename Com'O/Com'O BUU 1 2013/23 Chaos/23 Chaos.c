#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char n[1020];
    int i,len,cnt=0,ans=0;
    gets(n);
    len=strlen(n)-1;
    for(i=0;i<=len;i++)  n[i]-='0';
    while(n[len--]==0)  cnt++;
    while(cnt--)
        ans+=pow(10,cnt);
    printf("%d\n",ans);
    return 0;
}
