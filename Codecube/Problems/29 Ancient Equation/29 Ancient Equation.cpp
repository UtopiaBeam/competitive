#include<cstdio>
int n,t;
int pow(int a,int b){
    if(b==0)    return 1;
    int x=pow(a,b/2)%997;
    if(b%2)     return (a*x*x)%997;
    return (x*x)%997;
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&t);
        printf("%d ",2*pow(-1,t)+pow(4,t));
    }
    return 0;
}
