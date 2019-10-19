#include<cstdio>
int n,k,a[500002];
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e)/2,t=k;
    for(int i=0;i<n;i++){
        t-=a[i]/m+(a[i]%m!=0);
        if(t<0)     return bs(m+1,e);
        if(t==0 && i<n-1)   return bs(m+1,e);
    }
    return bs(s,m);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",bs(1,2000000));
    return 0;
}
