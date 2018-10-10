#include<stdio.h>
#include<math.h>
int main(){
    int A,B,C,a,b,c,d;
    scanf("%d %d %d",&A,&B,&C);
    a=1;
    while(a<=A){
        if(A%a==0){
            b=-fabs(C);
            while(b<=fabs(C)){
                if(b!=0&&C%b==0){
                    c=A/a,d=C/b;
                    if(B==a*d+b*c){
                        printf("%d %d %d %d\n",a,b,c,d);
                        return 0;
                    }
                }
                b++;
            }
        }
        a++;
    }
    printf("No Solution\n");
    return 0;
}
