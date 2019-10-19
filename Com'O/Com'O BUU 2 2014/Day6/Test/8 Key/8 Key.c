#include<stdio.h>
int x[1010],y[1010];
int main(){
    int a,b,k,i,n,m,cnt;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    while(m--){
        cnt=0;
        scanf("%d %d %d",&a,&b,&k);
        for(i=0;i<n;i++)
            if(x[i]>=a-k && x[i]<=a+k && y[i]>=b-k && y[i]<=b+k)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
