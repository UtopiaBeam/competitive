#include<cstdio>
#include<cstring>
int a,b,tmp;
int main(){
    scanf("%d %d",&a,&b);
    while(b){
        tmp*=10,tmp+=b%10,b/=10;
    }
    printf("%d\n",a+tmp);
    return 0;
}
