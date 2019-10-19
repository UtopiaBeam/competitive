#include<cstdio>
#include<algorithm>
using namespace std;
int st[300002],n,q,l,r,a[100002];
void bd(int s,int e,int in){
    if(s>e)     return ;
    if(s==e){
        st[in]=a[s];
        return ;
    }
    int m=(s+e)/2;
    bd(s,m,2*in+1);    bd(m+1,e,2*in+2);
    st[in]=min(st[2*in+1],st[2*in+2]);
}
int qr(int s,int e,int in){
    if(r<s || l>e)      return 1<<30;
    if(l<=s && e<=r)    return st[in];
    int m=(s+e)/2;
    return min(qr(s,m,2*in+1),qr(m+1,e,2*in+2));
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    bd(0,n-1,0);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&l,&r);
        printf("%d\n",qr(0,n-1,0));
    }
    return 0;
}
