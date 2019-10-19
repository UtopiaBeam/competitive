#include<cstdio>
int n,pre=1<<30,nw,cnt=0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&nw);
        cnt+=(nw>=80 || (nw>=20 && nw-pre>=10));
        pre=nw;
    }
    printf("%d\n",cnt);
    return 0;
}
