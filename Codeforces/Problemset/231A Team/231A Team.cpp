#include<cstdio>
int cnt=0,a,n;
int main(){
    scanf("%d",&n);
    while(n--){
        int t=0;
        for(int i=0;i<3;i++){
            scanf("%d",&a);
            t+=a;
        }
        if(t>=2)    cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
