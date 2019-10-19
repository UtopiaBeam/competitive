#include<cstdio>
int a[105],n,cnt0=0,cnt1=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2)     cnt1++;
        else    cnt0++;
    }
    if(cnt0==1){
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                printf("%d\n",i+1);     break;
            }
        }
    }
    else if(cnt1==1){
        for(int i=0;i<n;i++){
            if(a[i]%2){
                printf("%d\n",i+1);     break;
            }
        }
    }
    return 0;
}
