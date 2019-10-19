#include<stdio.h>
#include<string.h>
char a[110],b[110]="000";
int main(){
    int len,i;
    scanf(" %s",a);
    len=strlen(a);
    strcpy(&b[(len%4==0)?   0:4-(len%4)],a);
    for(i=0;i<len;i+=4)
        printf("%X",8*(b[i]-'0')+4*(b[i+1]-'0')+2*(b[i+2]-'0')+b[i+3]-'0');
    return 0;
}
