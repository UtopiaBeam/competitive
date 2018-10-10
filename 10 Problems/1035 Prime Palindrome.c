#include<stdio.h>
int main(){
    int n,i,j,chk;
    scanf("%d",&n);
    n--;
    while(++n){
        chk=0,i=n;
        while(i){
            chk=chk*10+i%10;
            i/=10;
        }
        if(chk==n){
            for(i=2;i*i<=n;i++){
                if(n%i==0)  chk=0;
            }
            if(chk) printf("%d\n",n);
            else    continue;
        }
        else    continue;
        return 0;
    }
}
