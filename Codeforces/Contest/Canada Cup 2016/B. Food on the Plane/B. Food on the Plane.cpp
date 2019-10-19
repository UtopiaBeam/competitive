#include<cstdio>
unsigned long long n,sum=0;
char ch,s[]="fedabc";
int main(){
    scanf("%I64d %c",&n,&ch);
    sum=(--n/4)*16;
    n&=3;
    if(n&1)     sum+=7;
    for(int i=0;s[i];i++)
        if(ch==s[i])
            sum+=i+1;
    printf("%I64d\n",sum);
    return 0;
}
