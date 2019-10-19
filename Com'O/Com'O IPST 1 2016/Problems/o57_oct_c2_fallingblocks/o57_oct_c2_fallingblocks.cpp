#include<cstdio>
int ft[100002],up[100002],down[100002];
int n,m,op,x,y,dx,dy;
void ud(int *t,int x,int v){
    for(;x<=n;x+=-x&x)  t[x]+=v;
}
int qr(int *t,int x){
    int sum=0;
    for(;x;x-=-x&x)     sum+=t[x];
    return sum;
}
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&op,&x,&y);
        if(op==1){
            dx=qr(ft,x)-qr(ft,x-1);
            dy=qr(ft,y+1)-qr(ft,y);
            if(dx>0)    ud(up,x,-1);
            if(dx<0)    ud(down,x,-1);
            if(dy>0)    ud(up,y+1,-1);
            if(dy<0)    ud(down,y+1,-1);
            ud(ft,x,1);
            ud(ft,y+1,-1);
            dx=qr(ft,x)-qr(ft,x-1);
            dy=qr(ft,y+1)-qr(ft,y);
            if(dx>0)    ud(up,x,1);
            if(dx<0)    ud(down,x,1);
            if(dy>0)    ud(up,y+1,1);
            if(dy<0)    ud(down,y+1,1);
        }
        if(op==2)   printf("%d %d\n",qr(ft,x),qr(ft,y));
        if(op==3)   printf("%d %d %d %d\n",qr(ft,x),qr(ft,y),qr(up,y)-qr(up,x),qr(down,y)-qr(down,x));
    }
    return 0;
}
