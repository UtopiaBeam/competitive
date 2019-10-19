#include<cstdio>
int st[400002],lz[400002],n,m,l,r,t;
void chk(int s,int e,int nw){
    if(lz[nw])
        st[nw]=(e-s+1)-st[nw];
    if(s!=e){
        lz[2*nw+1]+=lz[nw];     lz[2*nw+1]%=2;
        lz[2*nw+2]+=lz[nw];     lz[2*nw+2]%=2;
    }
    lz[nw]=0;
}
void ud(int s,int e,int nw){
    chk(s,e,nw);
    if(s>e || s>r || e<l)   return ;
    if(l<=s && e<=r){
        st[nw]=(e-s+1)-st[nw];
        if(s!=e){
            lz[2*nw+1]++;   lz[2*nw+1]%=2;
            lz[2*nw+2]++;   lz[2*nw+2]%=2;
        }
        return ;
    }
    int m=(s+e)/2;
    ud(s,m,2*nw+1);     ud(m+1,e,2*nw+2);
    st[nw]=st[2*nw+1]+st[2*nw+2];
}
int qr(int s,int e,int nw){
    chk(s,e,nw);
    if(s>e || s>r || e<l)   return 0;
    if(l<=s && e<=r)    return st[nw];
    int m=(s+e)/2;
    return qr(s,m,2*nw+1)+qr(m+1,e,2*nw+2);
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&t,&l,&r);
        if(t)       printf("%d\n",qr(1,n,1));
        else        ud(1,n,1);
    }
    return 0;
}
