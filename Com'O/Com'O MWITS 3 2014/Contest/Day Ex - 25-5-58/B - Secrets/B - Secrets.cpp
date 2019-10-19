#include<cstdio>
long long n,b=3;
int main(){
    scanf("%I64d",&n);
    while(n%b==0)   b*=3;
    printf("%I64d\n",n/b+1);
    return 0;
}
