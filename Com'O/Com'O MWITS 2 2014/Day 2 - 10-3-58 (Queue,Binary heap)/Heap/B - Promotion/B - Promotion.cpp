#include<cstdio>
#include<queue>
using namespace std;
priority_queue <long long> Max,Min;
int main(){
    int n;
    long long sum=0;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        while(m--){
            int num;
            scanf("%d",&num);
            Max.push(num);
        }
        sum+=Max.top();
        Max.pop();
        while(!Max.empty()){
            Min.push(-Max.top());
            Max.pop();
        }
        sum+=Min.top();
        Min.pop();
        while(!Min.empty()){
            Max.push(-Min.top());
            Min.pop();
        }
    }
    printf("%lld\n",sum);
    return 0;
}
