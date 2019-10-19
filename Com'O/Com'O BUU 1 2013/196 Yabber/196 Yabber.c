#include<stdio.h>
long long yab[100020],r;
int main(){
    int n,i,q,ch;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&yab[i]);
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&r);
        for(i=0,ch=1;i<n&&ch;i++)
            if(r==yab[i])   ch=0;
        if(ch)  printf("No\n");
        else    printf("Yes\n");
    }
    return 0;
}
