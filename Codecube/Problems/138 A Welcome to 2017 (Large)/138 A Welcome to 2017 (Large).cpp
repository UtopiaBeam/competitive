#include<cstdio>
int n;
int t;
int hs[4002];
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &t);
        hs[t]++;
    }
    for(int i = 0; i <= 2017/2; i++){
        if(hs[2017-i] == 1){
            printf("%d\n", 2017-i);
            return 0;
        }
        if(hs[2017+i] == 1){
            printf("%d\n", 2017+i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
