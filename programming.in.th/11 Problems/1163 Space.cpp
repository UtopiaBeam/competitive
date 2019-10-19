#include<cstdio>
int n;
void print(int num,int state){
    if(state){
        print(num/2,state-1);
        printf("%d",num%2);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<(1<<n)-1;i++)
        for(int j=0;j<n;j++)
            if((i>>j)%2==0){
                print(i,n);
                printf(" ");
                print(i+(1<<j),n);
                printf("\n");
            }
    return 0;
}
