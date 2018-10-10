#include<stdio.h>
int main(){
    int p,a,chk0=0,chk1=0,hp0,hp1;
    scanf("%d",&p);
    hp0=hp1=p,p*=2;
    while(p--){
        scanf("%d",&a);
        if(a%2) chk1++,chk0=0;
        else    chk0++,chk1=0;
        if(a%2)
            if(chk1>=3) hp0-=3;
            else        hp0--;
        else
            if(chk0>=3) hp1-=3;
            else        hp1--;
        if(hp0<=0){
            printf("1\n%d\n",a);
            return 0;
        }
        if(hp1<=0){
            printf("0\n%d\n",a);
            return 0;
        }
    }
}
