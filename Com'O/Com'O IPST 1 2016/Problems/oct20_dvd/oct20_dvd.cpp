#include<cstdio>
#include<algorithm>
using namespace std;
int mx[300002],mn[300002],a[100002],n,m,op,x,y;
void bd(int s,int e,int nw){
    if(s==e){
        mx[nw]=mn[nw]=s;
        a[s]=s;
        return ;
    }
    int m=(s+e)>>1;
    bd(s,m,nw<<1);  bd(m+1,e,nw<<1|1);
    mx[nw]=max(mx[nw<<1],mx[nw<<1|1]);
    mn[nw]=min(mn[nw<<1],mn[nw<<1|1]);
}
void ud(int s,int e,int nw,int in,int val){
    if(s==e){
        mx[nw]=mn[nw]=val;
        return ;
    }
    int m=(s+e)>>1;
    if(in<=m)   ud(s,m,nw<<1,in,val);
    else    ud(m+1,e,nw<<1|1,in,val);
    mx[nw]=max(mx[nw<<1],mx[nw<<1|1]);
    mn[nw]=min(mn[nw<<1],mn[nw<<1|1]);
}
int q_mn(int s,int e,int nw,int l,int r){
    if(s>e || e<l || s>r)   return 1<<30;
    if(l<=s && e<=r)    return mn[nw];
    int m=(s+e)>>1;
    int mn_l=q_mn(s,m,nw<<1,l,r),mn_r=q_mn(m+1,e,nw<<1|1,l,r);
    return min(mn_l,mn_r);
}
int q_mx(int s,int e,int nw,int l,int r){
    if(s>e || e<l || s>r)   return 0;
    if(l<=s && e<=r)    return mx[nw];
    int m=(s+e)>>1;
    int mx_l=q_mx(s,m,nw<<1,l,r),mx_r=q_mx(m+1,e,nw<<1|1,l,r);
    return max(mx_l,mx_r);
}
int main(){
    scanf("%d %d",&n,&m);
    bd(0,n-1,1);
    while(m--){
        scanf("%d %d %d",&op,&x,&y);
        if(op==0){
            swap(a[x],a[y]);
            ud(0,n-1,1,x,a[x]);
            ud(0,n-1,1,y,a[y]);
        }
        else{
            if(x==q_mn(0,n-1,1,x,y) && y==q_mx(0,n-1,1,x,y))
                printf("YES\n");
            else    printf("NO\n");
        }
    }
}
