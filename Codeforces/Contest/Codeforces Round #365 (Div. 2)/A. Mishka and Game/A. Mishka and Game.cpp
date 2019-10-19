#include<cstdio>
int n,a,b,c,d;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        if(a>b)     c++;
        if(b>a)     d++;
    }
    if(c>d)     printf("Mishka\n");
    else if(c<d)    printf("Chris\n");
    else    printf("Friendship is magic!^^\n");
    return 0;
}
