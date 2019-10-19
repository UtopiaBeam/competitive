#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int info;
    struct list *next;
}list;
list *head=NULL;
list *find(int n){
    list *node=head;
    while(node!=NULL){
        if(node->info==n)   return node;
        node=node->next;
    }
}
void insert(int n){
    list *node=(list *)malloc(sizeof(list)),*cur=head;
    node->info=n;
    node->next=NULL;
    if(head==NULL){
        head=node;
        return ;
    }
    if(n<head->info){
        node->next=head;
        head=node;
        return ;
    }
    while(cur->next!=NULL){
        if(cur->info<=n && n<=cur->next->info){
            node->next=cur->next;
            cur->next=node;
            return ;
        }
        else    cur=cur->next;
    }
    if(cur->next==NULL)     cur->next=node;
}
void del(int n){
    list *node=find(n),*cur=head;
    if(head!=NULL){
        while(cur->next!=node)  cur=cur->next;
        cur->next=node->next;
        free(node);
    }
}
void print(){
    list *cur=head;
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->next;
    }
    printf("\n");
}
int main(){
    for(int i=10;i>0;i--)
        insert(i);
    print();
    return 0;
}
