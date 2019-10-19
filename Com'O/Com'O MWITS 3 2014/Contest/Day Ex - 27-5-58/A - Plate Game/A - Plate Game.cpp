#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,r;
int main(){
    scanf("%d %d %d",&n,&m,&r);
    if(2*r>min(n,m))    printf("Second\n");
    else    printf("First\n");
    return 0;
}
