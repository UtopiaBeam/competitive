#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    if(k<abs(a)+abs(b)||(a+b-k)%2)    printf("No\n");
    else    printf("Yes\n");
    return 0;
}
