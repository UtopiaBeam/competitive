#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n<3)     printf("-1\n");
    else if(n==3)   printf("210\n");
    else{
        printf("1");
        for(int i=0;i<n-4;i++)  printf("0");
        if(n%6==4)  printf("050\n");
        else if(n%6==5) printf("080\n");
        else if(n%6==0) printf("170\n");
        else if(n%6==1) printf("020\n");
        else if(n%6==2) printf("200\n");
        else            printf("110\n");
    }
    return 0;
}
