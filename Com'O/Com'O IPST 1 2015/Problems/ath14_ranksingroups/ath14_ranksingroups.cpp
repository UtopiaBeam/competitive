#include<cstdio>
#define max(x,y) x>y? x:y
typedef struct AVL{
    int key,h;
    AVL *l,*r;
    AVL(int key) : key(key),l(NULL),r(NULL),h(1){}
}AVL;
AVL *root[100002];
int t,n,m,k,x,y,r[100002],cnt;
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
    q->r=p->l;
    p->l=q;
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
void del(AVL* p){
    if(!p)  return ;
    del(p->l);      del(p->r);
    root[x]=insert(root[x],p->key);
    delete p;
}
void ans(AVL* p){
    if(!p)      return ;
    ans(p->r);
    cnt++;
    if(p->key==x)   return ;
    ans(p->l);
}
int findr(int u){
    if(u!=r[u])     r[u]=findr(r[u]);
    return r[u];
}
void in(AVL* p){
    if(!p)      return ;
    printf("%d ",p->key);
    in(p->l);
    in(p->r);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)   r[i]=i,root[i]=insert(NULL,i);
        while(m--){
            scanf("%d %d",&k,&x);
            if(k==1){
                scanf("%d",&y);
                del(root[y]);
                r[y]=x;     root[y]=NULL;
            }
            else{
                int rx=findr(x);
//                printf("root of x = %d\n",rx);
                cnt=0;      ans(root[rx]);
//                printf("cnt = ");
                printf("%d\n",cnt);
            }
//            for(int i=1;i<=n;i++){
//                if(root[i]){
//                    printf("G%d : ",i);
//                    in(root[i]);
//                    printf("\n");
//                }
//            }
//            for(int i=1;i<=n;i++)   printf("No.%d is in G%d\n",i,r[i]);
        }
    }
    return 0;
}
