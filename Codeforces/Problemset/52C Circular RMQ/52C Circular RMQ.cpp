#include<cstdio>
#include<algorithm>
#define L long long
using namespace std;
int n,q,l,r;
L st[600002],lz[600002],a[300002],v;
char op[32];
void bd(int s,int e,int in){
    if(s>e)     return ;
    if(s==e){
        st[in]=a[s];
        return ;
    }
    int m=(s+e)/2;
    bd(s,m,2*in);       bd(m+1,e,2*in+1);
    st[in]=min(st[2*in],st[2*in+1]);
}
void ud(int s,int e,int l,int r,int in){
    if(lz[in]){
        st[in]+=lz[in];
        if(s!=e){
            lz[2*in]+=lz[in];
            lz[2*in+1]+=lz[in];
        }
        lz[in]=0;
    }
    if(s>e || l>e || r<s)   return ;
    if(l<=s && e<=r){
        st[in]+=v;
        if(s!=e){
            lz[2*in]+=v;
            lz[2*in+1]+=v;
        }
        return ;
    }
    int m=(s+e)/2;
    ud(s,m,l,r,2*in);       ud(m+1,e,l,r,2*in+1);
    st[in]=min(st[2*in],st[2*in+1]);
}
int qr(int s,int e,int l,int r,int in){
    if(s>e || l>e || r<s)   return 1<<30;
    if(lz[in]){
        st[in]+=lz[in];
        if(s!=e){
            lz[2*in]+=lz[in];
            lz[2*in+1]+=lz[in];
        }
        lz[in]=0;
    }
    if(l<=s && e<=r)    return st[in];
    int m=(s+e)/2;
    return min(qr(s,m,l,r,2*in),qr(m+1,e,l,r,2*in+1));
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",a+i);
    bd(0,n-1,1);
    scanf("%d ",&q);
    while(q--){
        gets(op);
        int cnt=0;
        for(int i=0;op[i];i++)
            cnt+=(op[i]==' ');
        if(cnt==1){
            sscanf(op,"%d %d",&l,&r);
            if(l>r)     printf("%d\n",min(qr(0,n-1,l,n-1,1),qr(0,n-1,0,r,1)));
            else        printf("%d\n",qr(0,n-1,l,r,1));
        }
        if(cnt==2){
            sscanf(op,"%d %d %I64d",&l,&r,&v);
            if(l>r)     ud(0,n-1,l,n-1,1),ud(0,n-1,0,r,1);
            else        ud(0,n-1,l,r,1);
        }
    }
    return 0;
}
