#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,len;
    char a[200],b[200];
    scanf("%s",a);
    memset(b,'0',sizeof b);
    len=strlen(a);
    if(len%3)
        strcpy(&b[3-(len%3)],a);
    else
        strcpy(b,a);
    len=strlen(b);
    for(i=0;i<len;i+=3)
        printf("%d",(b[i]-'0')*4+(b[i+1]-'0')*2+(b[i+2]-'0'));
    return 0;
}
