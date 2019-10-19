#include<stdio.h>
int main(){
    int a,i,str=0,end=0,n,cnt=0,max=-1<<20,chk=1,chplus=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(a>=0)    chplus=0;
        cnt+=a;
        if(chk){
            str=i;  chk=0;
        }
        if(cnt<0){
            end=i-1;    chk=1;
            cnt=0;
        }
        if(max<cnt)     max=cnt;
    }
    printf("%d %d\n%d\n",str,end,max);
    return 0;
}
