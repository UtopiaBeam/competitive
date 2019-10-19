#include<cstdio>
int t,p,q;
void f(int a,int b){
//    getchar();
//    printf("f(%d, %d)\n",a,b);
    if(a==1 && b==1)    return ;
    if(a>b){
        printf("R");
        f(b,a-b);
    }
    else{
        printf("L");
        f(b-a,a);
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d/%d",&p,&q);
        f(p,q);
        printf("\n");
    }
    return 0;
}
