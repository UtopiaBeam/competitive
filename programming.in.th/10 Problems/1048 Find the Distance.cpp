#include<stdio.h>
int ans=0;
int main(){
    int k,n,i,t;
    scanf("%d %d",&k,&n);
    for(i=0;i<n;i++){
        t=i^(i+1);
        while(t){
            if(t%2) ans++;
            t/=2;
        }
    }
    printf("%d\n",ans);
    return 0;
}
