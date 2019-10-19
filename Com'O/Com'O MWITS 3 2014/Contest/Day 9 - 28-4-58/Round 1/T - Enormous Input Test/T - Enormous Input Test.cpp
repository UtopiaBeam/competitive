#include<cstdio>
int cnt=0,a,n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a%k==0)  cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
