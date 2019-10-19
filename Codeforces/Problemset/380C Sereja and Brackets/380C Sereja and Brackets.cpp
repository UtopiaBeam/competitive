#include<cstdio>
#include<cstring>
struct S{
    int len,op,cl;
    S(int len=0,int op=0,int cl=0):
        len(len),op(op),cl(cl){}
};
int n,q,l,r;
S st[3000002];
char str[1000002];
void bd(int s,int e,int x){
    if(s>e)     return ;
    if(s==e){
        if(str[s]=='(')     st[x]=S(0,1,0);
        else    st[x]=S(0,0,1);
        return ;
    }
    int m=(s+e)/2;
    bd(s,m,2*x);    bd(m+1,e,2*x+1);
    S lf=st[2*x],rt=st[2*x+1];
    st[x].len=lf.len+rt.len;
    if(lf.op<=rt.cl){
        st[x].len += 2*lf.op;
        st[x].op = rt.op;
        st[x].cl = lf.cl + rt.cl - lf.op;
    }
    else{
        st[x].len += 2*rt.cl;
        st[x].op = lf.op - rt.cl + rt.op;
        st[x].cl = lf.cl;
    }
}
S qr(int s,int e,int x){
    if(s>e || l>e || r<s)   return S();
    if(l<=s && e<=r)    return st[x];
    int m=(s+e)/2;
    S lf=qr(s,m,2*x),rt=qr(m+1,e,2*x+1),t;
    t.len=lf.len+rt.len;
    if(lf.op<=rt.cl){
        t.len += 2*lf.op;
        t.op = rt.op;
        t.cl = lf.cl + rt.cl - lf.op;
    }
    else{
        t.len += 2*rt.cl;
        t.op = lf.op - rt.cl + rt.op;
        t.cl = lf.cl;
    }
    return t;
}
int main(){
    scanf(" %s",str+1);
    n=strlen(str+1);
    bd(1,n,1);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&l,&r);
        printf("%d\n",qr(1,n,1).len);
    }
    return 0;
}
