#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],n;
int main(){
    int i,j,d1,d2,d3,in1,in2,Max,Min,mind=1<<20;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i>1)   a[i]+=a[i-1];
    }
    for(i=1;i<n;i++)
        for(j=2;j<n;j++){
            d1=a[i],d2=a[j]-a[i],d3=a[n]-a[j];
            Max=max(max(d1,d2),d3);
            Min=min(min(d1,d2),d3);
            if(Max-Min<mind){
                mind=Max-Min;
                in1=i+1,in2=j+1;
            }
        }
    printf("%d %d\n",in1,in2);
    return 0;
}
