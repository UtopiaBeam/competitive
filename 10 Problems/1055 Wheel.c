#include<stdio.h>
int a[105],scr[30];
int main(){
    int x,k,i,j,n,in=1;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i%n]);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        while(x){
            if(a[in++%n]) x--;
        }
        while(!a[in%n])   in++;
        scr[i%k]+=a[in%n];
        a[in%n]=0;
    }
    for(i=0;i<k;i++)
        printf("%d\n",scr[i]);
    return 0;
}
