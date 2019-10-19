#include<cstdio>
#include<cstdlib>
typedef struct list{
    int num;
    struct list *r;
}list;
list *head=NULL,*cur;
list *build(int x){
    list *node=(list *)malloc(sizeof(list));
    node->num=x;
    node->r=NULL;
    return node;
}
void add(int x){
    list *node=build(x);
    node->r=cur->r;
    cur->r=node;
}
void tail(){
    while(cur->r!=NULL) cur=cur->r;
}
void remove(){
    if(cur->r==NULL)    return ;
    list *node=cur->r;
    cur->r=node->r;
    free(node);
}
void l(){
    while(cur->r!=NULL){
        printf("%d ",cur->num);
        cur=cur->r;
    }
    printf("%d\n",cur->num);
}
int main(){
    int n,t;
    char s[10];
    scanf("%d",&n);
    head=build(999);
    cur=head;
    while(n--){
        scanf(" %s",s);
        if(s[0]=='c')   printf("%d\n",cur->num);
        else if(s[0]=='a'){
            scanf("%d",&t);
            add(t);
        }
        else if(s[0]=='h')  cur=head;
        else if(s[0]=='n' && cur->r!=NULL)  cur=cur->r;
        else if(s[0]=='t')  tail();
        else if(s[0]=='r')  remove();
        else if(s[0]=='l')  l();
    }
    return 0;
}
