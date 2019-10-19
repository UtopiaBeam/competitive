#include<cstdio>
int n,a[1002],b[1002];
void in(int i){
    if(i<n){
        scanf("%d",&a[i]);
        b[a[i]]=1;
        in(i+1);
    }
}
void out(int i){
    if(i<n){
        printf("%d\n",a[i]);
        out(i+1);
    }
}
int aval(int i){
    if(i>n)     return 0;
    if(b[i])    return aval(i+1);
    return i;
}
void nextperm(int i){
    if(i==n)    return ;
    int nw=aval(a[i]+1);
    b[a[i]]=0,a[i]=0;
    if(nw){
        a[i]=nw,b[nw]=1;
        nextperm(i+1);
    }
    else    nextperm(i-1);
}
int main(){
    scanf("%d",&n);
    in(0);
    nextperm(n-1);
    out(0);
}
