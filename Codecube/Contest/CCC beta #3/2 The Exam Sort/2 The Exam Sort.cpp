#include<cstdio>
int n,a[1002],cnt=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=i;j<=n-i+1;j++){
            if(a[j]==i){
                if(i==j)    cnt++;
                else{
                    for(int k=j;k>i;k--)    a[k]=a[k-1];
                    a[i]=i;
                }
                break;
            }
        }
        for(int j=i+1;j<=n-i+1;j++){
            if(a[j]==n-i+1){
                if(n-i+1==j)    cnt++;
                else{
                    for(int k=j;k<n-i+1;k++)    a[k]=a[k+1];
                    a[n-i+1]=n-i+1;
                }
                break;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
