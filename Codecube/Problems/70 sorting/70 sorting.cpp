#include<cstdio>
int n,a[200002],b[200002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        b[t]=i;
    }
    for(int i=0;i<n;i++)    a[i]=b[a[i]];
    for(int i=1;i<n;i++)
        if(a[i]<a[i-1]){
            printf("%d\n",n-i);
            return 0;
        }
    printf("0\n");
}
