#include<stdio.h>
#include<string.h>
int main(){
    int a[110],b[110],c[30],n,k;
    int i,dice,state,pos=-1;
    memset(b,0,sizeof(int));
    memset(c,0,sizeof(int));
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        state=0;
        scanf("%d",&dice);
        while(state<=dice){
            if(b[pos]==0)   state++;
            pos++;  pos%=n;
        }
        b[pos]=1;
        c[i%k]+=a[pos];
    }
    for(i=0;i<k;i++)
        printf("%d\n",c[i]);
    return 0;
}
