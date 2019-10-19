#include<cstdio>
#include<cstdlib>
typedef struct T{
    int num;
    struct T *l,*r;
}T;
T *root=NULL;
int n,x;
T* insert(int x,T* node){
    if(node==NULL){
        node=(T *)malloc(sizeof(T));
        node->num=x,node->l=node->r=NULL;
        printf("*\n");
        return node;
    }
    if(x<node->num)     printf("L"),node->l=insert(x,node->l);
    else    printf("R"),node->r=insert(x,node->r);
    return node;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        root=insert(x,root);
    }
    return 0;
}
