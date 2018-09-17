#include<stdio.h>
#include<string.h>
int top=0;
char s[210],stack[210];
int main(){
    int i;
    scanf(" %s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='('||top==0||stack[top-1]!='(')   stack[top++]=s[i];
        else if(s[i]==')' && stack[top-1]=='(')    top--;
    }
    printf("%d\n",top);
    return 0;
}
