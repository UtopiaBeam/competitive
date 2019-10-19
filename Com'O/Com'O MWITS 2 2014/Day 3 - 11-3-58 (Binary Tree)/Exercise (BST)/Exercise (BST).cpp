#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef struct node{
    int info;
    struct node *l,*r;
}node;
node *root=NULL;
bool find(int n,node* now){
    if(now==NULL)       return false;
    if(now->info==n)    return true;
    if(n<now->info)
        return find(n,now->l);
    return find(n,now->r);
}
int findmax(node* now){
    if(now->r==NULL)     return now->info;
    return findmax(now->r);
}
int findmin(node* now){
    if(now->l==NULL)     return now->info;
    return findmin(now->l);
}
node *insert(int n,node* now){
    if(now==NULL){
        now=(node *)malloc(sizeof(node));
        now->info=n;
        now->l=now->r=NULL;
        return now;
    }
    else if(n<now->info){
        now->l=insert(n,now->l);
        return now;
    }
    else{
        now->r=insert(n,now->r);
        return now;
    }
    return now;
}
void del(int n,node* &now){
    if(!find(n,now))    return ;
    if(n<now->info)     del(n,now->l);
    else if(n>now->info)    del(n,now->r);
    else{
        if(now->l==NULL && now->r==NULL){
            free(now);  now=NULL;
            return ;
        }
        else if(now->l==NULL){
            node *tmp=now->r;
            free(now);
            now=tmp;
            return ;
        }
        else if(now->r==NULL){
            node *tmp=now->l;
            free(now);
            now=tmp;
            return ;
        }
        int tmp=findmax(now->l);
        now->info=tmp;
        del(tmp,now->l);
        return ;
    }
}
void preorder(node* now){
    if(now==NULL)   return ;
    printf("%d ",now->info);
    preorder(now->l);
    preorder(now->r);
}
void inorder(node* now){
    if(now==NULL)   return ;
    inorder(now->l);
    printf("%d ",now->info);
    inorder(now->r);
}
void postorder(node* now){
    if(now==NULL)   return ;
    postorder(now->l);
    postorder(now->r);
    printf("%d ",now->info);
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int num;
        char cmd[10];
        scanf(" %s",cmd);
        if(!strcmp(cmd,"insert")){
            scanf("%d",&num);
            root=insert(num,root);
        }
        if(!strcmp(cmd,"delete")){
            scanf("%d",&num);
            if(find(num,root)){
                del(num,root);
                printf("delete %d successful\n",num);
            }
            else    printf("delete %d not successful\n",num);
        }
        if(!strcmp(cmd,"find")){
            scanf("%d",&num);
            printf("find %d ",num);
            if(!find(num,root))  printf("not ");
            printf("successful\n");
        }
        if(!strcmp(cmd,"min"))
            printf("%d\n",findmin(root));
        if(!strcmp(cmd,"max"))
            printf("%d\n",findmax(root));
        if(!strcmp(cmd,"preorder")){
            preorder(root);     printf("\n");
        }
        if(!strcmp(cmd,"inorder")){
            inorder(root);      printf("\n");
        }
        if(!strcmp(cmd,"postorder")){
            postorder(root);    printf("\n");
        }
    }
    return 0;
}
