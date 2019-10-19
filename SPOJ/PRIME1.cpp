#include<cstdio>
#define max(a,b) a>b? a:b
int n,l,r;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&l,&r);
        for(int i=max(l,2);i<=r;i++){
            int chk=1;
            for(int j=2;j*j<=i && chk;j++)
                if(i%j==0)     chk=0;
            if(chk)     printf("%d\n",i);
        }
        printf("\n");
    }
    return 0;
}
