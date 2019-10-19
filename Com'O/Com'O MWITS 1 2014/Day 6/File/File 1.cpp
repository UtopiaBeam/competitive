#include<stdio.h>
#include<string.h>
char s[100010];
int main(){
    int cnt=0,i,j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    gets(s);
    for(i=1;i<strlen(s);i++)
        for(j=0;j+2*i<strlen(s);j++)
            if(s[j]==s[j+i] && s[j]==s[j+2*i] && s[j]=='1')  cnt++;
    printf("%d\n",cnt);
    return 0;
}
