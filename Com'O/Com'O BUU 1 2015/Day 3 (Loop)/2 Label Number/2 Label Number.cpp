#include<cstdio>
int a,b,_0=0,_1=0,_2=0,_3=0,_4=0,_5=0,_6=0,_7=0,_8=0,_9=0;
int main(){
    scanf("%d %d",&a,&b);
    for(int j=a;j<=b;j++){
        int i=j;
        while(i){
            if(i%10==0)     _0++;
            else if(i%10==1)    _1++;
            else if(i%10==2)    _2++;
            else if(i%10==3)    _3++;
            else if(i%10==4)    _4++;
            else if(i%10==5)    _5++;
            else if(i%10==6)    _6++;
            else if(i%10==7)    _7++;
            else if(i%10==8)    _8++;
            else    _9++;
            i/=10;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",_0,_1,_2,_3,_4,_5,_6,_7,_8,_9);
    return 0;
}
