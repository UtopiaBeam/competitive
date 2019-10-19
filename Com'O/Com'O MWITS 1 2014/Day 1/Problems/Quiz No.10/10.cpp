#include<cstdio>
using namespace std;
int main(){
    int i,chk;
    double n,sum=0.00,Max=-1<<20,mid=-1<<20;
    for(i=0;i<3;i++){
        scanf("%lf",&n);
        if(Max<n)   Max=n;
        if(n>mid && n<Max)  mid=n;
        sum+=n/3.00;
    }
    scanf("%d",&chk);
    switch(chk){
        case 1:{
            printf("%.3lf\n",sum);
            break;
        }
        case 2:{
            printf("%.3lf\n",n);
            break;
        }
        case 3:{
            printf("%.3lf\n",Max);
            break;
        }
    }
    return 0;
}
