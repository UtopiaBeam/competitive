#include<cstdio>
int main(){
    for(int t=0;t<5;t++){
        int n;
        scanf("%d",&n);
        int s=n,m=0;
        while(s)    m*=10,m+=s%10,s/=10;
        for(int j=1;m;j++){
            int p=1;
            for(int k=0;k<j;k++)    p*=m%10;
            s+=p,m/=10;
        }
        if(n==s)    printf("Y");
        else    printf("N");
    }
    return 0;
}
