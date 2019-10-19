#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef struct list{
    char a[40];
    struct list *l,*r;
}list;
list *head=NULL,*cur;
list *build(char *w){
    list *node=(list *)malloc(sizeof(list));
    strcpy(node->a,w);
    node->l=node->r=NULL;
    return node;
}
void insert(char *w){
    list *node=build(w);
    node->r=cur->r;
    if(cur->r!=NULL)    cur->r->l=node;
    node->l=cur;    cur->r=node;
    cur=node;
}
void back(){
    if(cur->l==NULL)    return ;
    list *node=cur;
    cur=cur->l;
    cur->r=node->r;
    if(cur->r!=NULL)    cur->r->l=cur;
    free(node);
}
void del(){
    if(cur->r==NULL)    return ;
    list *node=cur->r;
    cur->r=node->r;
    if(cur->r!=NULL)    cur->r->l=cur;
    free(node);
}
int main(){
    int n;
    char ch,s[40];
    head=build("xx");
    cur=head;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&ch);
        if(ch=='l' && cur->l!=NULL)   cur=cur->l;
        else if(ch=='r' && cur->r!=NULL)    cur=cur->r;
        else if(ch=='i'){
            scanf(" %s",s);
            insert(s);
        }
        else if(ch=='b')    back();
        else    del();
    }
    while(head->r!=NULL){
        head=head->r;
        printf("%s ",head->a);
    }
    return 0;
}
