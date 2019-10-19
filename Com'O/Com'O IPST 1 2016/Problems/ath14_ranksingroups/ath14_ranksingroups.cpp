#include<cstdio>
#include<algorithm>
using namespace std;
//Reflected AVL Tree
struct AVL{
    int v,h;
    AVL *l,*r;
    AVL(int v):
        v(v),h(0),l(NULL),r(NULL){}
};
AVL *rt[300002];
int q,n,m,op,x,y,r[300002],cnt,rx,ry;
int fr(int x){
    if(x!=r[x])     r[x]=fr(r[x]);
    return r[x];
}
int fh(AVL *p){
    return (p!=NULL)*(p->h);
}
int bfac(AVL *p){
    return fh(p->r)-fh(p->l);
}
int udh(AVL *p){
    p->h=max(fh(p->l),(p->r))+1;
}
AVL *bal(AVL *p){
    ;
}
AVL *add(AVL *p,int v){
    if(!p)      return new AVL(v);
    if(v>p->v)  p->l=add(p->l,v);
    else        p->r=add(p->r,v);
    return bal(p);
}
void mrg(AVL *px,AVL *py){
    ;
}
void qr(AVL *p){
    if(!p)      return ;
    qr(p->l);
    cnt++;
    if(x==p->v){
        printf("%d\n",cnt);
        return ;
    }
    qr(p->r);
}
void clr(AVL *p){
    if(!p)      return ;
    clr(p->l);  clr(p->r);
    delete p;
}
void solve(){
    for(int i=1;i<=n;i++)
        r[i]=i,rt[i]=add(NULL,i);
    while(m--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d %d",&x,&y);
            rx=fr(x),ry=fr(y);
            mrg(rt[rx],rt[ry]);
        }
        else{
            scanf("%d",&x);
            rx=fr(x);
            cnt=0;      qr(rt[rx]);
        }
    }
    for(int i=1;i<=n;i++)
        clr(rt[i]);
}
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        solve();
    }
    return 0;
}
