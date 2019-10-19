/*
TASK: AddPoly
LANG: C
AUTHOR: Natchapol Srisang
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int coe,deg;
    struct list *next;
}list;
list *headA=NULL,*headB=NULL,*curA,*curB;
list *new(int coe,int deg){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->coe=coe;
    node->deg=deg;
    node->next=NULL;
    return node;
}
void insertA(int n,int i){
    list *node;
    node=new(n,i);
    node->next=curA->next;
    curA->next=node;
    curA=curA->next;
}
void insertB(int n,int i){
    list *node;
    node=new(n,i);
    node->next=curB->next;
    curB->next=node;
    curB=curB->next;
}
void sum(){
    curA=headA,curB=headB;
    while(curB->next!=NULL){
        curB->coe+=curA->coe;
        curB->deg+=curA->coe;
        curA=curA->next;
        curB=curB->next;
    }
    curB->coe+=curA->coe;
    curB->deg+=curA->coe;
}
void print(){
    int chk=1;
    list *cur;
    cur=headB;
    if(cur->coe!=0){
        printf("%dx^%d",cur->coe,cur->deg);
        chk=0;
    }
    if(cur->next!=NULL){
        cur=cur->next;
        if()
        else if(cur->coe == -1)
            printf(" - x^%d",cur->deg);
        else if(cur->coe < 0)
            printf(" - %dx^%d",cur->coe*(-1),cur->deg);
        else if(cur->coe == 1)
            printf(" + x^%d",cur->deg);
        else if(cur->coe > 1)
            printf(" + %dx^%d",cur->coe,cur->deg);
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    headA=new(0,0);     curA=headA;
    headB=new(0,0);     curB=headB;
    while(n--){
        for(i=19;i>=0;i--){
            scanf("%d",&a);
            insertA(a,i);
        }
        for(i=19;i>=0;i--){
            scanf("%d",&b);
            insertB(b,i);
        }
        sum();      print();
    }
    return 0;
}
