#include<stdio.h>
int a[200010],task,n;
int bs(int p,int q){
    int mid=(p+q)/2;
    if(p>q)     return mid+1;
    if(a[mid]==task)    return mid;
    else if(a[mid]>task)    bs(mid+1,q);
    else    bs(p,mid-1);
}
int main(){
    int m,i,ord;
    scanf("%d %d",&n,&m);
    for(i=n;i>0;i--)
        scanf("%d",&a[i]);
    while(m--){
        scanf("%d",&task);
        ord=bs(1,n);
        printf("%d\n",ord);
    }
    return 0;
}
