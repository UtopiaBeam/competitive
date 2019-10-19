#include<stdio.h>
int main(){
    int i,n,adr=0,bru=0,gor=0,max=-1;
    char Adr[4]="ABC",Bru[5]="BABC",Gor[7]="CCAABB",ans[120];
    scanf("%d",&n);
    scanf(" %s",ans);
    for(i=0;i<n;i++){
        if(ans[i]==Adr[i%3])    adr++;
        if(ans[i]==Bru[i%4])    bru++;
        if(ans[i]==Gor[i%6])    gor++;
    }
    max=(adr>bru)?  adr:bru;
    max=(max>gor)?  max:gor;
    printf("%d\n",max);
    if(adr==max)    printf("Adrian\n");
    if(bru==max)    printf("Bruno\n");
    if(gor==max)    printf("Goran\n");
    return 0;
}
