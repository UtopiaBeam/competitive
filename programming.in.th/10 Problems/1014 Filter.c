#include<stdio.h>
int mic[3010],w,h,n,x,a,an1=0,an2=0;
int main(){
    int i;
    scanf("%d %d %d",&w,&h,&n);
    while(n--){
        scanf("%d %d",&x,&a);
        mic[x]++,mic[x+a]--;
    }
    for(i=0;i<w;i++){
        mic[i]+=mic[i-1];
        if(mic[i]==1)   an1+=h;
        if(mic[i]==0)   an2+=h;
    }
    printf("%d %d\n",an2,an1);
    return 0;
}
