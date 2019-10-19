#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int mn[300002],mx[300002],n,m,t,l,r;
void u_mn(int in){
    if(in==0)     return ;
    mn[in]=min(mn[in<<1],mn[(in<<1)+1]);
    u_mn(in>>1);
}
void u_mx(int in){
    if(in==0)     return ;
    mx[in]=max(mx[in<<1],mx[(in<<1)+1]);
    u_mx(in>>1);
}
int g_mn(int s,int e,int nw,int h){
    int L=nw*h,R=(nw+1)*h-1;
    if(e<L || s>R)      return 2e9;
    if(s<=L && R<=e)    return mn[nw];
    return min(g_mn(s,e,nw<<1,h>>1),g_mn(s,e,(nw<<1)+1,h>>1));
}
int g_mx(int s,int e,int nw,int h){
    int L=nw*h,R=(nw+1)*h-1;
    if(e<L || s>R)      return -2e9;
    if(s<=L && R<=e)    return mx[nw];
    return max(g_mx(s,e,nw<<1,h>>1),g_mx(s,e,(nw<<1)+1,h>>1));
}
int main(){
    scanf("%d %d",&n,&m);
    int h=(int)ceil(log2(n));
    for(int i=1;i<=n;i++){
        mn[(1<<h)+i-1]=mx[(1<<h)+i-1]=i;
        u_mn(((1<<h)+i-1)>>1);
        u_mx(((1<<h)+i-1)>>1);
    }
    while(m--){
        scanf("%d %d %d",&t,&l,&r);
        l++,r++;
        if(t){
            int Mn=g_mn((1<<h)+l-1,(1<<h)+r-1,1,1<<h);
            int Mx=g_mx((1<<h)+l-1,(1<<h)+r-1,1,1<<h);
            if(Mn==l && Mx==r)
                printf("YES\n");
            else    printf("NO\n");
        }
        else{
            int pl=mn[(1<<h)+l-1],pr=mn[(1<<h)+r-1];
            mn[(1<<h)+l-1]=mx[(1<<h)+l-1]=pr;
            u_mn(((1<<h)+l-1)>>1);      u_mx(((1<<h)+l-1)>>1);
            mn[(1<<h)+r-1]=mx[(1<<h)+r-1]=pl;
            u_mn(((1<<h)+r-1)>>1);      u_mx(((1<<h)+r-1)>>1);
        }
    }
    return 0;
}
