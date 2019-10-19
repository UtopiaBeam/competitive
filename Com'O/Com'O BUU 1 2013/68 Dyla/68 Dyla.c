#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int ord;
    int dyla;
    struct list *next;
}list;
list *head=NULL,*cur;
list *new(int Ord,int Dyla){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->dyla=Dyla;
    node->ord=Ord;
    node->next=NULL;
    return node;
}
void add(int Ord,int Dyla){
    list *node;
    node=new(Ord,Dyla);
    cur=head;
    while(cur->next!=NULL){
        if(cur->dyla < node->dyla && node->dyla < cur->next->dyla){
            node->next=cur->next;
            cur->next=node;
            break ;
        }
        cur=cur->next;
    }
}
void print(){
    cur=head;
    while(cur->next!=NULL){
        printf("%d\n",cur->next->ord);
        cur=cur->next;
    }
}
int main(){
    int n,i,Dyla;
    scanf("%d",&n);
    head=new(0,0);
    cur=head;
    for(i=0;i<n;i++){
        scanf("%d",&Dyla);
        add(i,Dyla);
    }
    print();
    return 0;
}
