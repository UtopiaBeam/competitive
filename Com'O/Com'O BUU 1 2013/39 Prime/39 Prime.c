#include<stdio.h>
int a[2802],p[410]={2},n,i,j,cnt=1,lim=1;
int main(){
    scanf("%d",&n);
    if(n==1){
        printf("2\n");  return 0;
    }
    for(i=3;i<2800;i+=2)
        a[i]=1;
    for(i=3;i*i<2800;i+=2)
        if(a[i])
            for(j=i*i;j<2800;j+=i) a[j]=0;
    for(i=3;i<2800;i+=2)
        if(a[i])    p[lim++]=i;
    for(i=3;n>1;i+=2){
        int chk=1;
        for(j=1;p[j]*p[j]<=i && j<lim;j++)
            if(i%p[j]==0){
                chk=0;  break;
            }
        if(chk)     n--;
    }
    printf("%d\n",i-2);
    return 0;
}
