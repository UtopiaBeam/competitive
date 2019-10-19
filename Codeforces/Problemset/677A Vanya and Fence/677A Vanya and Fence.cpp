#include<cstdio>
int n,h,t,cnt=0;
int main(){
    scanf("%d %d",&n,&h);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t<=h)    cnt++;
        else        cnt+=2;
    }
    printf("%d\n",cnt);
    return 0;
}
