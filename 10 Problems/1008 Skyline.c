#include<stdio.h>
int str=1<<20,end=0,L[300],R[300],n,chk=1;
int main(){
    int i,l,h,r;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&l,&h,&r);
        for(i=l;i<=r;i++){
            if(i!=l && L[i]<h)  L[i]=h;
            if(i!=r && R[i]<h)  R[i]=h;
        }
        if(str>l)   str=l;
        if(end<r)   end=r;
    }
    for(i=str;i<=end;i++){
        if(L[i]!=R[i])
            printf("%d %d ",i,R[i]);
    }
    printf("\n");
    return 0;
}
