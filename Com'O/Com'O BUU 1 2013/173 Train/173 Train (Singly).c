/*
TASK: Train
LANG: C
AUTHOR: Natchapol Srisang
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
    int a;
    struct list *next;
}list;
list *head=NULL,*cur;
list *Build(int n){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->a=n;
    node->next=NULL;
    return node;
}
void Add(int n){
    list *node;
    node=Build(n);
    node->next=cur->next;
    cur->next=node;
}
void Remove(){
    list *node;
    if(cur->next!=NULL){
        node=cur->next;
        cur->next=node->next;
        node->next=NULL;
        free(node);
    }
}
void Call(){
    printf("%d\n",cur->a);
}
void Tail(){
    while(cur->next!=NULL)
        cur=cur->next;
}
void List(){
    while(cur->next!=NULL){
        printf("%d ",cur->a);
        cur=cur->next;
    }
    printf("%d\n",cur->a);
}
int main(){
    char str[10];
    int n,m;
    head=Build(999);
    cur=head;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",str);
        if(!strcmp(str,"head"))     cur=head;
        if(!strcmp(str,"tail"))     Tail();
        if(!strcmp(str,"next"))     cur=cur->next;
        if(!strcmp(str,"add")){
            scanf("%d",&m);    Add(m);
        }
        if(!strcmp(str,"remove"))   Remove();
        if(!strcmp(str,"call"))     Call();
        if(!strcmp(str,"list"))     List();
    }
    return 0;
}
