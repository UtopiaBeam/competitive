#include<cstdio>
long long l,r;
int main(){
    scanf("%I64d %I64d",&l,&r);
    if(l%2)     l++;
    if(l+2>r)   printf("-1\n");
    else    printf("%I64d %I64d %I64d\n",l,l+1,l+2);
    return 0;
}
