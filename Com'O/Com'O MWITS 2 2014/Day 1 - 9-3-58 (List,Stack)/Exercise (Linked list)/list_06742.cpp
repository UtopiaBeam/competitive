#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int num,fre;
    struct list* next;
}list;
list *head=NULL;
list *build(int n){
    list *node=(list *)malloc(sizeof(list));
    node->num=n,node->fre=1,node->next=NULL;
    return node;
}
list *find(int n){
    list *cur=head;
    while(cur!=NULL){
        if(cur->num==n)   return cur;
        cur=cur->next;
    }
}
void insert(int n){
    list *node=build(n),*cur=head;
    if(head==NULL){
        head=node;
        return ;
    }
    if(n<head->num){
        node->next=head;
        head=node;
        return ;
    }
    while(cur->next!=NULL){
        if(cur->num<=n && n<=cur->next->num){
            node->next=cur->next;
            cur->next=node;
            return ;
        }
        else    cur=cur->next;
    }
    if(cur->next==NULL)     cur->next=node;
}
void del(int n){
    list *cur=head,*node=find(n);
    while(cur->next!=node)  cur=cur->next;
    cur->next=node->next;
    free(node);
}
void print(){
    list *cur=head;
    while(cur!=NULL){
        printf("%d %d\n",cur->num,cur->fre);
        cur=cur->next;
    }
}
int main(){
    int n;
    while(scanf("%d",&n) && n!=0){
        if(n>0){
            list *node=find(n);
            if(node==NULL)   insert(n);
            else    (node->fre)++;
        }
        else{
            list *node=find(-n);
            if(node==NULL)  printf("Data not found\n");
            else{
                (node->fre)--;
                if(node->fre==0)    del(-n);
            }
        }
    }
    print();
    return 0;
}
