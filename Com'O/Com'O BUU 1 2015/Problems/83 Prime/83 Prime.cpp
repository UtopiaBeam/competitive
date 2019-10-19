#include<cstdio>
int a[7400002],p=2,n,i,j,cnt=1,lim=1;
int main(){
    scanf("%d",&n);
    if(n==1){
        printf("2\n");  return 0;
    }
    for(i=3;i<7400000;i+=2)
        a[i]=1;
    for(i=3;i*i<7400000;i+=2)
        if(a[i])    for(j=i*i;j<7400000;j+=i) a[j]=0;
    for(i=3,j=1;i<7400000 && j<n;i+=2)
        if(a[i])    p=i,j++;
    printf("%d\n",p);
    return 0;
}
