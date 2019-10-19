#include<cstdio>
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    if(c==0){
        if(a==b)    printf("YES\n");
        else        printf("NO\n");
    }
    else if((b-a)%c==0 && (b-a)/c>=0)      printf("YES\n");
    else    printf("NO\n");
    return 0;
}
