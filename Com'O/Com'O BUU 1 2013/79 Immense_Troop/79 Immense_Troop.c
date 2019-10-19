#include<stdio.h>
long long cnt;
int x2,y2;
void walk(int x1,int y1){
    if(x1==x2 && y1==y2){
        cnt++;  return ;
    }
    if(x1<x2)   walk(x1+1,y1);
    if(y1<y2)   walk(x1,y1+1);
}
int main(){
    int q,x1,y1;
    scanf("%d",&q);
    while(q--){
        cnt=0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        walk(x1,y1);
        printf("%lld\n",cnt%500000003);
    }
    return 0;
}
