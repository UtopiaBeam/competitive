/*
TASK: Train
LANG: C
AUTHOR: Natchapol Srisang
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
    char a[50];
    struct list *l,*r;
}list;
list *head=NULL,*cur;
list *create(char *str){
    list *node;
    node=(list *)malloc(sizeof(list));
    strcpy(node->a,str);
    node->l=NULL;
    node->r=NULL;
    return node;
}
void insert(char *str){
    list *node;
    node=create(str);
    node->r=cur->r;
    node->l=cur;
    if(cur->r!=NULL)    cur->r->l=node;
    cur->r=node;
    cur=cur->r;
}
void left(){
    if(cur->l!=NULL)    cur=cur->l;
}
void right(){
    if(cur->r!=NULL)    cur=cur->r;
}
void back(){
    list *node=cur;
    if(cur->l!=NULL){
        cur=cur->l;
        cur->r=node->r;
        if(cur->r!=NULL)    cur->r->l=cur;
        free(node);
    }
}
void del(){
    list *node;
    if(cur->r!=NULL){
        node=cur->r;
        cur->r=node->r;
        if(cur->r!=NULL)    cur->r->l=cur;
        free(node);
    }
}
void print(){
    while(head->r!=NULL){
        printf("%s ",head->r->a);
        head=head->r;
    }
    printf("\n");
}
int main(){
    char s[50],*word;
    int n,i;
    head=create("xxx");
    cur=head;
    scanf("%d\n",&n);
    while(n--){
        gets(s);
        if(s[0]=='l')   left();
        if(s[0]=='r')   right();
        if(s[0]=='i'){
            word=&s[2];
            insert(word);
        }
        if(s[0]=='b')   back();
        if(s[0]=='d')   del();
    }
    print();
    return 0;
}
