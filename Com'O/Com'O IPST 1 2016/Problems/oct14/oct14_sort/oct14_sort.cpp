#include<cstdio>
int n,a[1002];
void input(int i){
    if(i==n)    return ;
    scanf("%d",a+i);
    input(i+1);
}
int fmin(int i){
    if(i==n-1)    return i;
    int in=fmin(i+1);
    if(a[i]<a[in])  return i;
    return in;
}
void ssort(int i){
    if(i==n)    return ;
    int in=fmin(i),t;
    t=a[i],a[i]=a[in],a[in]=t;
    printf("%d\n",a[i]);
    ssort(i+1);
}
int main(){
    scanf("%d",&n);
    input(0);
    ssort(0);
    return 0;
}
