#include<cstdio>
#include<algorithm>
using namespace std;
char a[105];
long long b,s,c,nb,ns,nc,pb,ps,pc,n,cnt;
bool chk(long long t){
    long long m=0;
    if(nb<b*t)  m+=(b*t-nb)*pb;
    if(ns<s*t)  m+=(s*t-ns)*ps;
    if(nc<c*t)  m+=(c*t-nc)*pc;
    if(m<=n)    return true;
    return false;
}
int main(){
    scanf(" %s",a);
    for(int i=0;a[i];i++){
        if(a[i]=='B')   b++;
        if(a[i]=='S')   s++;
        if(a[i]=='C')   c++;
    }
    scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d",&nb,&ns,&nc,&pb,&ps,&pc,&n);
    long long l=1,r=2*n;
    while(l<r){
        long long m=(l+r+1)/2;
        if(chk(m))      l=m+1;
        else    r=m;
    }
//    printf("%I64d\n",l-1);
    return 0;
}
