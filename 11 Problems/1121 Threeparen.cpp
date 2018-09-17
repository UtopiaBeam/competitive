#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100010],stack[50010];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        int len=strlen(a),top=0;
        for(int i=0;i<len;i++){
            if(top==0 || stack[top-1]-a[i]==0 || abs(stack[top-1]-a[i])>2)
                stack[top++]=a[i];
            else if((a[i]==')' && stack[top-1]=='(') ||
                    (a[i]==']' && stack[top-1]=='[') ||
                    (a[i]=='}' && stack[top-1]=='{'))    top--;
        }
        if(top)     printf("no\n");
        else        printf("yes\n");
    }
    return 0;
}
