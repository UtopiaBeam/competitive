#include<cstdio>
int n,w,x,h,px=0,ph=0,mxh=0,a[500002],cnt=0;
int main(){
    scanf("%d %d",&n,&w);
    while(n--){
        scanf("%d %d",&x,&h);
        if(h>ph)    a[h]++;
        if(mxh<h)   mxh=h;
        px=x,ph=h;
    }
    if(px<w && ph)  cnt++;
    for(int i=1;i<=mxh;i++) cnt+=a[i];
    printf("%d\n",cnt);
    return 0;
}
