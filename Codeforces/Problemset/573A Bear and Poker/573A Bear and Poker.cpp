#include<cstdio>
int n,a[100005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        while(a[i]%2==0)   a[i]/=2;
        while(a[i]%3==0)   a[i]/=3;
    }
    for(int i=1;i<n;i++)
        if(a[i-1]!=a[i]){
            printf("No\n");     return 0;
        }
    printf("Yes\n");
    return 0;
}
