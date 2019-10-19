#include<cstdio>
int n,k,a[22][22];
void f(int i,int j,int num){
    if(num==k+n*n)  return ;
    if(a[i][j])     i=(i+n+2)%n,j=(j+n-1)%n;
    a[i][j]=num;
    f((i+n-1)%n,(j+n+1)%n,num+1);
}
int main(){
    scanf("%d %d",&n,&k);
    f(0,n/2,k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
