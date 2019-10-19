#include<cstdio>
long long n;
int main(){
    scanf("%I64d",&n);
    if(n>0)     printf("%I64d\n",(n*(n+1))/2);
    else        printf("%I64d\n",1-(n*(n-1))/2);
    return 0;
}
