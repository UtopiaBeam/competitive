#include<cstdio>
int main(){
    int m,x[102];
    for(int i=0;i<30;i++){
        scanf("%d",&x[i]);
        if(x[i]<=50)    m++;
    }
    if(x[0]>=50 && x[1]>=50 && x[2]<50 && x[3]<50)  printf("yes\n");            //1
    else if(x[0]>=50 && x[1]>=50 && x[2]>=50 && x[3]<50)    printf("yes\n");    //2
    else if(x[0]>=50 && x[1]<50 && x[2]>=50 && x[3]>=50 && m!=15)    printf("yes\n");    //3
    else if(x[0]>=50 && x[1]>=50 && x[2]>=50 && x[3]>=50)   printf("no\n");    //4
    else if(x[0]<50 && x[1]<50 && x[2]>=50 && x[3]>=50)    printf("yes\n");    //6
    else if(x[0]<50 && x[1]<50 && x[2]<50 && x[3]<50)    printf("no\n");    //7
    else if(x[0]<50 && x[1]>=50 && x[2]>=50 && x[3]<50)    printf("yes\n");    //8
    else if(x[0]<50 && x[1]<50 && x[2]>=50 && x[3]>=50)   printf("yes\n");    //9
    else    printf("no\n");     //5,10
    return 0;
}
