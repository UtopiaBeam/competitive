#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct AVL{
    int key,h;
    AVL *l,*r;
    AVL(int key) : key(key),l(NULL),r(NULL),h(1){}
}AVL;
int findh(AVL* p){
    return p? p->h : 0;
}
int bfac(AVL* p){
    return findh(p->r) - findh(p->l);
}
void uph(AVL* p){
    p->h=max(findh(p->l),findh(p->r))+1;
}
AVL* rotateright(AVL* p){
    AVL *q=p->l;
    p->l=q->r;
    q->r=p;
    uph(p);     uph(q);
    return q;
}
AVL* rotateleft(AVL* p){
    AVL *q=p->r;
    p->r=q->l;
    q->l=p;
    uph(p);     uph(q);
    return q;
}
AVL* balance(AVL* p){
    uph(p);
    int fac=bfac(p);
    if(fac==2){
        if(bfac(p->r)<0)    p->r=rotateright(p->r);
        return rotateleft(p);
    }
    if(fac==-2){
        if(bfac(p->l)>0)    p->l=rotateleft(p->l);
        return rotateright(p);
    }
    return p;
}
AVL* insert(AVL* p,int k){
    if(!p)  return new AVL(k);
    if(k < p->key)  p->l=insert(p->l,k);
    else    p->r=insert(p->r,k);
    return balance(p);
}
bool find(AVL* p,int k){
    if(!p)      return false;
    if(p->key==k)   return true;
    if(k<p->key)    return find(p->l,k);
    return find(p->r,k);
}
AVL *root=NULL;
int main(){
    int n,m,x;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d",&x);
        root=insert(root,x);
    }
    while(m--){
        scanf("%d",&x);
        if(find(root,x))    printf("y\n");
        else    printf("n\n");
    }
    return 0;
}
