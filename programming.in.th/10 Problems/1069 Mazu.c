#include<stdio.h>
int top=0;
char stack[100010];
int main(){
    char ch;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&ch);
        if(top==0||(top>0 && stack[top-1]!=ch))
            stack[top++]=ch;
        else{
            top--;
        }
    }
    printf("%d\n",top);
    if(top==0){
        printf("empty\n");
        return 0;
    }
    else{
        for(i=top-1;i>=0;i--)
            printf("%c",stack[i]);
        printf("\n");
    }
    return 0;
}
