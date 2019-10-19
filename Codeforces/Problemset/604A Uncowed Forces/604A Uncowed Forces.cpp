#include<cstdio>
#include<algorithm>
float m[8],w[8],hs,hu,ans=0;
int main(){
    for(int i=1;i<=5;i++)
        scanf("%f",&m[i]);
    for(int i=1;i<=5;i++)
        scanf("%f",&w[i]);
    scanf("%f %f",&hs,&hu);
    for(int i=1;i<=5;i++)
        ans+=std::max(0.3*500*i,(1-m[i]/250.0)*500*i-50*w[i]);
    ans+=hs*100-hu*50;
    printf("%.0f\n",ans);
    return 0;
}
