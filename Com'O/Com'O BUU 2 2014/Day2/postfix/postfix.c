#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int chk=0;
typedef struct list{
    char a;
    struct list *next;
}list;
list *top=NULL;
list *add(char ch){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->a=ch;
    node->next=NULL;
    return node;
}
void pop(){
    list *node=top;
    top=top->next;

}
void push(char ch){
    list *node;
    node=add(ch);

}
int main(){
    char ch;
    int n;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&ch);
        if(isalnum(ch)){
            if(chk) printf(" %c",ch);
            else    printf("%c",ch);
            chk=0;
        }
        else if(ch==' ')    chk=1;
        else{
            if(ch!='(')    chk=1;
            push(ch);
        }
    }
}
