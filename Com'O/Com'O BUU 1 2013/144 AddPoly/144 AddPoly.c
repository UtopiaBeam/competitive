#include<stdio.h>
int main(){
    int a[30],b[30],n,i,chk,ch;
    scanf("%d",&n);
    while(n--){
        chk=1,ch=1;
        for(i=19;i>=0;i--)
            scanf("%d",&a[i]);
        for(i=19;i>=0;i--){
            scanf("%d",&b[i]);
            a[i]+=b[i];
            if(a[i]!=0)     chk=0;
        }
        for(i=19;i>=0&&!chk;i--){
            if(a[i]!=0&&ch){
                if(i==0)            printf("%d\n",a[i]);
                else if(i==1)       printf("%dx",a[i]);
                else if(a[i]==1)    printf("x^%d",i);
                else                printf("%dx^%d",a[i],i);
                ch=0;
            }
            else if(i==1){
                if(a[i]>0)      printf(" + %dx",a[i]);
                else if(a[i]<0) printf(" - %dx",-1*a[i]);
            }
            else if(i==0){
                if(a[i]>0)      printf(" + %d",a[i]);
                else if(a[i]<0) printf(" - %d",-1*a[i]);
            }
            else if(a[i]==1)    printf(" + x^%d",i);
            else if(a[i]==-1)   printf(" - x^%d",i);
            else if(a[i]>0)     printf(" + %dx^%d",a[i],i);
            else if(a[i]<0)     printf(" - %dx^%d",-1*a[i],i);
        }
        if(chk)     printf("0");
        printf("\n");
    }
    return 0;
}
