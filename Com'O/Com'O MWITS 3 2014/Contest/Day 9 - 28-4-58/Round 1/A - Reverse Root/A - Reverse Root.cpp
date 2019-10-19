#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
vector <double> a;
double t;
int main(){
    while(scanf("%lf",&t)!=EOF){
        a.push_back(t);
    }
    for(int i=a.size()-1;i>=0;i--)
        printf("%.4lf\n",sqrt(a[i]));
    return 0;
}
