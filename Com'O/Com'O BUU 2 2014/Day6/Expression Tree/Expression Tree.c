#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct tree{
    char ch;
    struct tree *l,*r;
}tree;
tree *root=NULL,*stack[300];
int top=0;
tree *new(char cha){
    tree *node;
    node=(tree *)malloc(sizeof(tree));
    node->ch=cha;   node->l=NULL;   node->r=NULL;
    return node;
}
void merge(){
    stack[top]->r=stack[top-1];
    stack[top]->l=stack[top-2];
    stack[top-2]=stack[top];
    top--;
}
void in(tree *node){
    if(node!=NULL){
        if(isalpha(node->ch))
            printf("%c",node->ch);
        else{
            printf("(");
            in(node->l);
            printf("%c",node->ch);
            in(node->r);
            printf(")");
        }
    }
}
int main(){
    char s[300];
    int len,i;
    gets(s);    len=strlen(s);
    for(i=0;i<len;i++){
        stack[top]=new(s[i]);
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            merge();
        }
        else    top++;
    }
    root=stack[0];
    in(root);   printf("\n");
    return 0;
}
