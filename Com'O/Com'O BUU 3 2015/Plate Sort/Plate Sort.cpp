#include<cstdio>
int q,n,t,a[300002];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            a[t]=i;
        }
        int cnt=0;
        for(int i=n-1;i>0;i--){
            if(a[i]>a[i+1]){
                cnt++;      a[i]=-1;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
