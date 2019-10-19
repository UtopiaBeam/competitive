#include<cstdio>
int a,ans[1002]={1},n,la=1;
int main(){
    scanf("%d %d",&a,&n);
    while(n--){
        for(int i=0;i<la;i++)   ans[i]*=a;
        for(int i=0;i<la;i++)
            if(ans[i]>10){
                if(i==la-1)     la++;
                ans[i+1]+=ans[i]/10;
                ans[i]%=10;
            }
    }
    for(int i=la-1;i>=0;i--)    printf("%d",ans[i]);
    return 0;
}
