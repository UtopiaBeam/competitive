#include<stdio.h>
int mic[110],n;
int main(){
    int i,chk=1;
    mic[6]=1,mic[9]=1,mic[20]=1;
    for(i=1;i<=100;i++)
        if(mic[i])
            mic[i+6]=1,mic[i+9]=1,mic[i+20]=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        if(mic[i]){
            printf("%d\n",i);
            chk=0;
        }
    if(chk) printf("no\n");
    return 0;
}
