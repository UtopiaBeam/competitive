#include<cstdio>
#include<algorithm>
using namespace std;
struct S{
    int sm,lsm,rsm,bsm;
};
S st[150002];
int n,q,a[50002],t,x,y;
S mrg(S t1,S t2){
    return ((S){t1.sm+t2.sm,max(t1.lsm,t1.sm+t2.lsm),
            max(t2.rsm,t1.rsm+t2.sm),max(max(t1.bsm,t2.bsm),t1.rsm+t2.lsm)});
}
void bd(int s,int e,int in){
    if(s==e){
        st[in]=(S){a[s],a[s],a[s],a[s]};
        return ;
    }
    int m=(s+e)/2;
    bd(s,m,2*in);   bd(m+1,e,2*in+1);
    st[in]=mrg(st[2*in],st[2*in+1]);
}
void ud(int s,int e,int in){
    if(s==e){
        st[in]=(S){y,y,y,y};
        return ;
    }
    int m=(s+e)/2;
    if(x<=m)    ud(s,m,2*in);
    else        ud(m+1,e,2*in+1);
    st[in]=mrg(st[2*in],st[2*in+1]);
}
S qr(int s,int e,int in){
    if(x<=s && e<=y)    return st[in];
    int m=(s+e)/2;
    if(y<=m)    return qr(s,m,2*in);
    if(x>m)     return qr(m+1,e,2*in+1);
    return mrg(qr(s,m,2*in),qr(m+1,e,2*in+1));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    bd(1,n,1);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&t,&x,&y);
        if(t)       printf("%d\n",qr(1,n,1).bsm);
        else        ud(1,n,1);
    }
    return 0;
}
