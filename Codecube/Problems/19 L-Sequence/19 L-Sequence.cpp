#include<cstdio>
int a[1005],n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(k--){
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i]){
                for(int j=i-1;j<n;j++)
                    a[j]=a[j+1];
                break;
            }
        }
        n--;
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
