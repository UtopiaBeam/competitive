#include<cstdio>
int a[100005],n,t,cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        a[t]++;
    }
    for(int i=1;i<=n;i++){
        while(a[i]>1){
            int in=i+1;
            while(a[in])  in++;
            a[in]=1,cnt+=in-i,a[i]--;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
