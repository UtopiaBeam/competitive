#include<stdio.h>
#include<string.h>
char a[110],ch;
int main(){
    int len,cnt=0,i;
    scanf(" %s %c",a,&ch);
    len=strlen(a);
    for(i=0;i<len;i++)
        if(a[i]==ch)    cnt++;
    printf("%d\n",cnt);
    return 0;
}
