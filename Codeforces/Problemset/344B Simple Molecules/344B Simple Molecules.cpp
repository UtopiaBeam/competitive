#include<cstdio>
int a[5],b[3];
int main(){
    for(int i=0;i<3;i++)
        scanf("%d",&a[i]);
    a[3]=1<<20,a[4]=-10;
    while(a[0] || a[1] || a[2]){
        if((a[0]==0 && a[1]==0 && a[2]>0) ||
           (a[0]==0 && a[2]==0 && a[1]>0) ||
           (a[1]==0 && a[2]==0 && a[0]>0)){
            printf("Impossible\n");
            return 0;
        }
        int min=3,max=4;
        for(int i=0;i<3;i++){
            if(a[i]>0 && a[min]>a[i])     min=i;
            if(a[i]>0 && a[max]<=a[i])    max=i;
        }
        if(min==0){
            if(max==1)  b[0]++;
            if(max==2)  b[2]++;
        }
        if(min==1){
            if(max==0)  b[0]++;
            if(max==2)  b[1]++;
        }
        if(min==2){
            if(max==0)  b[2]++;
            if(max==1)  b[1]++;
        }
        a[min]--,a[max]--;
    }
    for(int i=0;i<3;i++)
        printf("%d ",b[i]);
    return 0;
}
