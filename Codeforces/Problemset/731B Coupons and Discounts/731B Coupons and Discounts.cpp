#include<cstdio>
int n,a[200002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++){
        a[i]%=2;
        if(a[i]==0)     continue;
        if(a[i+1]==0){
            printf("NO\n");
            return 0;
        }
        a[i]--,a[i+1]--;
    }
    printf("YES\n");
    return 0;
}
