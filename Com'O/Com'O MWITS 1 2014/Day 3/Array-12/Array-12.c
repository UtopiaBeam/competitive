#include<stdio.h>
#include<string.h>
char a[50];
int main(){
    int len;
    scanf(" %s",a);
    len=strlen(a);
    if(strcmp(&a[len-4],"buri"))    printf("No\n");
    else    printf("Yes\n");
    return 0;
}
