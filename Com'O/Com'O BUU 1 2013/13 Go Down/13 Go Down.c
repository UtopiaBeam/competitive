#include<stdio.h>
int main(){
    int n,x1,y1,x2,y2,area=0,lnow=0,wnow=0,lchk,wchk,t;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        lchk=x2-x1,wchk=y2-y1;
        if(lchk<wchk)   t=lchk,lchk=wchk,wchk=t;
        if(lchk>lnow||wchk>wnow)    area+=lchk*wchk;
        lnow=lchk,wnow=wchk;
    }
    printf("%d\n",area);
    return 0;
}
