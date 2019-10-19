#include<stdio.h>
int main(){
    int n,i,sum=0,num,max=-(-1u/2)-1,str,end,chk=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(sum+num>=0){
            sum+=num;
            if(chk) str=i,chk=0;
            if(sum>max) max=sum,end=i;
        }
        else
            sum+=num;
    }
}
