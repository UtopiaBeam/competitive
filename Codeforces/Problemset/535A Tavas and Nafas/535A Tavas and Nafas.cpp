#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n==0)            printf("zero");
    else if(n==10)      printf("ten");
    else if(n==11)      printf("eleven");
    else if(n==12)      printf("twelve");
    else if(n==13)      printf("thirteen");
    else if(n==15)      printf("fifteen");
    else if(n==18)      printf("eighteen");
    else{
        switch(n/10){
            case 2:     printf("twenty");  break;
            case 3:     printf("thirty");  break;
            case 4:     printf("forty");   break;
            case 5:     printf("fifty");   break;
            case 6:     printf("sixty");   break;
            case 7:     printf("seventy"); break;
            case 8:     printf("eighty");  break;
            case 9:     printf("ninety");   break;
        }
        if(n/10>1 && n%10)    printf("-");
        switch(n%10){
            case 1:     printf("one");  break;
            case 2:     printf("two");  break;
            case 3:     printf("three");    break;
            case 4:     printf("four"); break;
            case 5:     printf("five"); break;
            case 6:     printf("six");  break;
            case 7:     printf("seven");    break;
            case 8:     printf("eight");    break;
            case 9:     printf("nine"); break;
        }
        if(n/10==1)     printf("teen");
    }
    return 0;
}
