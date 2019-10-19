//"node" means operated node
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
    char a[50];
    struct list* l;
    struct list* r;
};
typedef struct list list;
list* head=NULL,*cur;
//Create Node
list* create(char *str){
    list* node;
    node=(list *)malloc(sizeof(list));
    strcpy(node->a,str);
    node->l=NULL;
    node->r=NULL;
    return node;
}
//Insert Node
void insert(char *str){
    list* node=create(str);
    node->r=cur->r;
    node->l=cur;
    if(cur->r!=NULL)
        cur->r->l=node;
    cur->r=node;
    cur=cur->r;
}
//Move Pointer to LEFT
void left(){
    if(cur->l!=NULL)    cur=cur->l;
}
//Move Pointer to RIGHT
void right(){
    if(cur->r!=NULL)    cur=cur->r;
}
//Backspace
void back(){
    list* p=cur->l;
    list* node=cur;
    if(cur->l!=NULL){
        if(cur->r==NULL)
            p->r=NULL;
        else{
            p->r=p->r->r;
            p->r->l=p;
        }
        cur=p;
        free(node);
    }
}
//Delete
void del(){
    list* node;
    if(cur->r!=NULL){
        node=cur->r;
        cur->r=node->r;
        if(cur->r!=NULL)    cur->r->l=cur;
        free(node);
    }
}
//Print List
void print(){
    while(head->r!=NULL){
        head=head->r;
        printf("%s ",head->a);
    }
    printf("\n");
}
int main(){
    int n;
    char s[50],*word;
    head=create("xxx");
    cur=head;
    scanf("%d\n",&n);
    while(n--){
        gets(s);
        if(s[0]=='i'){
            word=&s[2];
            insert(word);
        }
        else if(s[0]=='l')  left();
        else if(s[0]=='r')  right();
        else if(s[0]=='b')  back();
        else                del();
    }
    print();
    return 0;
}
