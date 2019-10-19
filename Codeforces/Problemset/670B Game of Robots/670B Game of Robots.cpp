#include<cstdio>
int n,k,a[100002];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;;i++){
        k-=i;
        if(k==0){
            printf("%d\n",a[i]);
            return 0;
        }
        if(k<0){
            printf("%d\n",a[k+i]);
            return 0;
        }
    }
}
