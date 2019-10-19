#include<stdio.h>
int main(){
    double w,h,bmi;
    scanf("%lf %lf",&w,&h);
    bmi=w/(h*h);
    if(bmi<15.00)       printf("Very severely underweight\n");
    else if(bmi<16.00)  printf("Severely underweight\n");
    else if(bmi<18.50)  printf("Underweight\n");
    else if(bmi<25.00)  printf("Normal\n");
    else if(bmi<30.00)  printf("Overwieght\n");
    else if(bmi<35.00)  printf("Moderately obese\n");
    else if(bmi<40.00)  printf("Severely obese\n");
    else                printf("Very severely obese\n");
    return 0;
}
