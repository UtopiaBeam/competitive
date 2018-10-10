#include<stdio.h>
int a,sum=0,n,m,l,k,c,i,j;
int main(){
    scanf("%d %d %d %d %d",&n,&m,&l,&k,&c);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
           scanf("%d",&a);
           sum+=a;
        }
    if(sum%c)   printf("%d\n",l*k+sum/c+1);
    else    printf("%d\n",l*k+sum/c);
    return 0;
}
