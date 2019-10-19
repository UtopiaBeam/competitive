#include<cstdio>
int n,mx=2;
double x[25],y[25];
double s(int i,int j){
    if(x[i]==x[j])      return 1e9;
    return (y[j]-y[i])/(x[j]-x[i]);
}
int main(){
    scanf("%d",&n);
    if(n<2){
        printf("%d\n",n);
        return 0;
    }
    for(int i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++){
            int cnt=2;
            for(int k=j+1;k<n;k++){
                if(s(i,j)==s(j,k))  cnt++;
                if(cnt>mx)  mx=cnt;
            }
        }
    printf("%d\n",mx);
    return 0;
}
