#include<cstdio>
int n,a[2502],mx=-1,s=0,e=0,f,t,sum=0,chk=1,chp=1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(sum+a[i]>0){
            sum+=a[i],chp=0,t=i;
            if(chk)     f=i,chk=0;
            if(sum>mx)  mx=sum,s=f,e=t;
        }
        else        sum=0,chk=1;
    }
    if(chp)     printf("Empty sequence\n");
    else{
        for(int i=s;i<=e;i++)   printf("%d ",a[i]);
        printf("\n%d\n",mx);
    }
    return 0;
}
