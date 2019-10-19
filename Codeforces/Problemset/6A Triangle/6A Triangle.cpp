#include<stdio.h>
int a[5],chk=0;
int main(){
    for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<2;i++){
        for(int j=i+1;j<3;j++){
            for(int k=j+1;k<4;k++){
                if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i]){
                    printf("TRIANGLE\n");   return 0;
                }
                if(a[i]+a[j]==a[k]||a[i]+a[k]==a[j]||a[j]+a[k]==a[i])
                    chk=1;
            }
        }
    }
    if(chk)     printf("SEGMENT\n");
    else        printf("IMPOSSIBLE\n");
    return 0;
}
