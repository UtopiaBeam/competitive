#include<stdio.h>
#include<math.h>
int chk[20],n;
void fac(int i){
    int k=0;
    while(k<n){
        chk[k++]=i%2;
        i/=2;
    }
}
int main(){
    int i,j,s[20],b[20],lim,S,B,min=1<<20,dif;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&s[i],&b[i]);
    lim=(int)pow(2,n);
    for(i=1;i<lim;i++){
        S=1,B=0;
        fac(i);
//        for(j=0;j<n;j++)
//            printf("%d ",chk[j]);
//        printf("\n");
        for(j=0;j<n;j++)
            if(chk[j])
                S*=s[j],B+=b[j];
        dif=(int)fabs(S-B);
        if(min>dif)     min=dif;
    }
    printf("%d\n",min);
    return 0;
}
