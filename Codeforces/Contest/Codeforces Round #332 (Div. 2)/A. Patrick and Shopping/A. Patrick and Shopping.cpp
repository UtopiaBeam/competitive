#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    printf("%d\n",min(min(a+b+c,2*a+2*b),min(2*a+2*c,2*b+2*c)));
    return 0;
}
