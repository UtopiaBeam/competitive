#include<stdio.h>
int i=0,v=0,x=0,l=0,c=0,d,k;
void cnt1(int n){
    if(n<=3)    i+=n;
    else if(n==4)
        i++,v++;
    else if(n<9)
        v++,i+=n-5;
    else    i++,x++;
}
void cnt10(int n){
    if(n<=3)    x+=n;
    else if(n==4)
        x++,l++;
    else if(n<9)
        l++,x+=n-5;
    else    x++,c++;
}
int main(){
    scanf("%d",&d);
    for(k=1;k<=d;k++)
        if(k>=100){
            c+=k/100;
            cnt10((k/10)%10);
            cnt1(k%10);
        }
        else if(k>=10){
            cnt10(k/10);
            cnt1(k%10);
        }
        else    cnt1(k);
    printf("%d %d %d %d %d\n",i,v,x,l,c);
    return 0;
}
