#include<stdio.h>
int main(){
    int n,i,sum=0,num,max=-(-1u/2)-1,str,end,chk=1;
    int maxnum=-(-1u/2)-1,chp=1,at,from;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(num>maxnum)  maxnum=num,at=i;
        if(sum+num>=0){
            chp=0;
            sum+=num;
            if(chk) from=i,chk=0;
            if(sum>max) max=sum,end=i,str=from;
        }
        else
            sum=0,chk=1;
    }
    if(chp)
        printf("%d %d\n%d\n",at,at,maxnum);
    else
        printf("%d %d\n%d\n",str,end,max);
    return 0;
}
