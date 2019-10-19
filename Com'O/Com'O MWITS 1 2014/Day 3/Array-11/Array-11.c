#include<stdio.h>
#include<string.h>
char a[50];
int main(){
    int len,cnt=0,i;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++)
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            cnt++;
    printf("%d\n",cnt);
    return 0;
}
