#include<cstdio>
#include<algorithm>
using namespace std;
int n,x,y,r,mn=1e9;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&x,&y,&r);
        if(y>=0)    mn=min(mn,y-r);
        else    mn=min(mn,-y-r);
    }
    if(mn<=0)   printf("-1\n");
    else    printf("%d\n",mn);
    return 0;
}
