#include<stdio.h>
#include<string.h>
char s[30],c[2];
int main(){
    scanf(" %s %s",s,c);
    if(strstr(s,c))   printf("Yes\n");
    else    printf("No\n");
    return 0;
}
