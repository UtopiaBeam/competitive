#include<stdio.h>
int a[100010];
int main(){
    int n,m,q,i,r,s;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&r,&s);
        a[r]++; a[s+1]--;
        /*for(i=r;i<=s;i++)
            a[i]++;*/
    }
    for(i=1;i<=n;i++)
        a[i]+=a[i-1];
    scanf("%d",&q);
    while(q--){
        scanf("%d",&r);
        printf("%d\n",a[r]);
    }
    return 0;
}
