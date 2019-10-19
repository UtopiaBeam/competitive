#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int info;
    struct list *next;
}list;
int main(){
    list *head=(list *)malloc(sizeof(list));
    head->info=5;
    head->next=NULL;
    printf("%d\n",head->info);
    list *cur=(list *)malloc(sizeof(list));
    cur->next=NULL;
    cur->info=10;
    head->next=cur;
    cur=(list *)malloc(sizeof(list));
    cur->info=8;
    cur->next=NULL;
    cur->next=head->next;
    head->next=cur;
    cur=head;
    while(cur!=NULL){
        printf("%d ",cur->info);
        cur=cur->next;
    }
    return 0;
}
