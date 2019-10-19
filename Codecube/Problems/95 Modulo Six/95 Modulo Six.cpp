#include<cstdio>
int n,s,a[100002];
int main(){
    scanf("%d %d",&n,&s);
    if(s%3 || s%2 && n==1){
        printf("-1\n");
        return 0;
    }
}
