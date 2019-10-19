#include<cstdio>
struct S{
    int c[3];
};
S st[300002];
int n,q,l,r,op;
int lz[300002];
void shf(int x){
    int t=st[x].c[2];
    st[x].c[2]=st[x].c[1];
    st[x].c[1]=st[x].c[0];
    st[x].c[0]=t;
}
void bld(int s,int e,int x){
    if(s>e)     return ;
    if(s==e){
        st[x].c[0]=1;
        return ;
    }
    int m=(s+e)/2;
    bld(s,m,2*x+1);     bld(m+1,e,2*x+2);
    st[x].c[0]=st[2*x+1].c[0]+st[2*x+2].c[0];
}
void ud(int s,int e,int x){
    if(lz[x]){
        for(int i=0;i<lz[x];i++)
            shf(x);
        if(s!=e){
            lz[2*x+1]=(lz[2*x+1]+lz[x])%3;
            lz[2*x+2]=(lz[2*x+2]+lz[x])%3;
        }
        lz[x]=0;
    }
    if(s>e || l>e || r<s)       return ;
    if(l<=s && e<=r){
        shf(x);
        if(s!=e){
            lz[2*x+1]=(lz[2*x+1]+1)%3;
            lz[2*x+2]=(lz[2*x+2]+1)%3;
        }
        return ;
    }
    int m=(s+e)/2;
    ud(s,m,2*x+1);      ud(m+1,e,2*x+2);
    for(int i=0;i<3;i++)
        st[x].c[i]=st[2*x+1].c[i]+st[2*x+2].c[i];
}
S qr(int s,int e,int x){
    S t=S();
    if(s>e || l>e || r<s)       return t;
    if(lz[x]){
        for(int i=0;i<lz[x];i++)
            shf(x);
        if(s!=e){
            lz[2*x+1]=(lz[2*x+1]+lz[x])%3;
            lz[2*x+2]=(lz[2*x+2]+lz[x])%3;
        }
        lz[x]=0;
    }
    if(l<=s && e<=r)    return st[x];
    int m=(s+e)/2;
    S t1=qr(s,m,2*x+1);
    S t2=qr(m+1,e,2*x+2);
    for(int i=0;i<3;i++)
        t.c[i]=t1.c[i]+t2.c[i];
    return t;
}
int main(){
    scanf("%d %d",&n,&q);
    bld(0,n-1,0);
    while(q--){
        scanf("%d %d %d",&op,&l,&r);
        if(op==0)   ud(0,n-1,0);
        else        printf("%d\n",qr(0,n-1,0).c[0]);
        printf("\n");
    }
    return 0;
}
