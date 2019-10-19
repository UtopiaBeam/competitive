#include<cstdio>
int n,a[1002];
void input(int i){
    if(i==n)    return ;
    scanf("%d",&a[i]);
    input(i+1);
}
void output(int i){
    if(i==n)    return ;
    printf("%d\n",a[i]);
    output(i+1);
}
int min(int x,int y){
    return x<y? x:y;
}
int findmn(int i){
    if(i==n-1)    return i;
    int in=findmn(i+1);
    if(a[i]<a[in])      return i;
    return in;
}
void srt(int i){
    if(i==n)    return ;
    int mn=findmn(i),t;
    t=a[i],a[i]=a[mn],a[mn]=t;
    srt(i+1);
}
int main(){
    scanf("%d",&n);
    input(0);
    srt(0);
    output(0);
}
