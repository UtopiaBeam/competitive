#include<cstdio>
int main(){
    long long w,l,cnt=0;
    scanf("%I64d %I64d",&w,&l);
    if(w>l)     w+=l,l=w-l,w-=l;
    while(w>0 && l>0){
        cnt+=l/w;
        l%=w,w+=l,l=w-l,w-=l;
    }
    printf("%I64d\n",cnt);
    return 0;
}
