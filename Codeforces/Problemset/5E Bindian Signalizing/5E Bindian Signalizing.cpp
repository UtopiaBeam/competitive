#include<bits/stdc++.h>
using namespace std;
long long a[1000010],sum=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    printf("%I64d\n",sum);
    return 0;
}
