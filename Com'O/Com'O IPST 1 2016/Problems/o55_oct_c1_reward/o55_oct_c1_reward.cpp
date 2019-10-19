#include<cstdio>
int n,b,a[500002];
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e)/2,t=b;
    for(int i=0;i<n;i++)
        t-=a[i]/m+(a[i]%m>0);
    if(t<0)     return bs(m+1,e);
    return bs(s,m);
}
int main(){
    scanf("%d %d",&n,&b);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    printf("%d\n",bs(1,(int)2e6));
    return 0;
}
