#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
    int a;
    struct list *l;
    struct list *r;
};
typedef struct list list;
list *head=NULL,*cur;
list *Build(int m){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->a=m;
    node->l=NULL;
    node->r=NULL;
    return node;
}
list *Add(int m){
    list *node=Build(m);
    node->r=cur->r;
    node->l=cur;
    if(cur->r!=NULL)
        cur->r->l=node;
    cur->r=node;
}
void Head(){
    cur=head;
}
void Tail(){
    while(cur->r!=NULL) cur=cur->r;
}
void Next(){
    if(cur->r!=NULL)    cur=cur->r;
}
void Remove(){
    list *node;
    if(cur->r!=NULL){
        node=cur->r;
        cur->r=node->r;
        if(cur->r!=NULL)
            cur->r->l=cur;
        free(node);
    }
}
void Call(){
    printf("%d\n",cur->a);
}
void List(){
    printf("%d ",cur->a);
    while(cur->r!=NULL){
        cur=cur->r;
        printf("%d ",cur->a);
    }
    printf("\n");
}
int main(){
    int m,n,i;
    char com[10];
    head=Build(999);
    cur=head;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",com);
        if(!strcmp(com,"head"))     Head();
        if(!strcmp(com,"next"))     Next();
        if(!strcmp(com,"tail"))     Tail();
        if(!strcmp(com,"add")){
            scanf("%d",&m);
            Add(m);
        }
        if(!strcmp(com,"remove"))   Remove();
        if(!strcmp(com,"call"))     Call();
        if(!strcmp(com,"list"))     List();
    }
    return 0;
}
