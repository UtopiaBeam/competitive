#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef struct T{
public:
    int num;
    struct T *l,*r;
}T;
T *root=NULL;
T *insert(int x,T* node){
    if(node==NULL){
        node=(T *)malloc(sizeof(T));
        node->num=x;
        node->l=node->r=NULL;
    }
    else if(x<node->num)  node->l=insert(x,node->l);
    else        node->r=insert(x,node->r);
    return node;
}
bool find(int x,T* node){
    if(node==NULL)      return false;
    if(x==node->num)    return true;
    if(x<node->num)     return find(x,node->l);
    return find(x,node->r);
}
void del(int x,T* node){
    if(x<node->num)     del(x,node->l);
    else if(x>node->num)    del(x,node->r);
    else{
        if(node->l==NULL && node->r==NULL){
            free(node);     node=NULL;
        }
        else if(node->l==NULL){
            T *tmp=node->r;
        }
    }
}
int main(){
    int n=0;
    while(n--){
        int x;
        char a[12];
        scanf(" %s",a);
        if(!strcmp(a,"insert")){
            scanf("%d",&x);
            root=insert(x,root);
        }
        else if(!strcmp(a,"delete")){
            scanf("%d",&x);
            printf("delete %d ",x);
            if(find(x,root))    del(x,root);
            else    printf("not ");
            printf("successful\n");
        }
    }
}
