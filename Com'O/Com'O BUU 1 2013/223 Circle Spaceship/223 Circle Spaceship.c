#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,min=-1u/2;
    scanf("%d",&n);
    int x,y,r,ship,i;
    for(i=0;i<n;i++){
        scanf("%d %d %d",&x,&y,&r);
        ship=abs(y)-r;
        if(ship<=0){
            printf("-1\n");
            return 0;
        }
        else if(min>ship)
            min=ship;
    }
    printf("%d\n",min);
    return 0;
}
