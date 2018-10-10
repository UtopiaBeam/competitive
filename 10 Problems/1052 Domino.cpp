#include<cstdio>
int x[100005],h[100005],l[100005],r[100005],n,L=1,R=n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&x[i],&h[i]);
    l[1]=1,r[n]=1;
    for(int i=2;i<=n;i++){
        int max=i;
        for(int j=i-1;j>0 && x[j]>x[i]-h[i];j--)
            if(l[max]<l[j])    max=j;
        if(max==i)  l[i]=1;
        else    l[i]=l[max]+i-max;
    }
    for(int i=n-1;i>0;i--){
        int max=i;
        for(int j=i+1;j<=n && x[j]<x[i]+h[i];j++)
            if(r[max]<r[j])    max=j;
        if(max==i)  r[i]=1;
        else    r[i]=r[max]+max-i;
    }
    for(int i=2;i<=n;i++)
        if(l[L]<l[i])     L=i;
    for(int i=n-1;i>0;i--)
        if(r[R]<=r[i])     R=i;
    if(l[L]>r[R])   printf("%d L\n",L);
    else if(l[L]<r[R])  printf("%d R\n",R);
    else if(L>R)    printf("%d R\n",R);
    else    printf("%d L\n",L);
    return 0;
}
