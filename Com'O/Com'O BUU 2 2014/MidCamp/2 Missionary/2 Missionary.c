#include<stdio.h>
int n,m,t,cnt=0;
int main(){
    int q,i;
    scanf("%d",&q);
    while(q--){
        cnt=0;
        scanf("%d %d %d",&n,&m,&t);
        if(n<m){
            printf("-1\n");
            continue;
        }
        for(i=0;i<t&&n>0;i++){
            cnt++;
            if(i%2){
                n--;
                if(m>0)     m--;
                else if(n>0)    n--;
            }
        }
        cnt+=2*(m+n)-1;
        printf("%d\n",cnt);
    }
    return 0;
}
