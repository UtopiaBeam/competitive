#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int> heap;
int main(){
    int p,num;
    char ch;
    scanf("%d",&p);
    while(p--){
        scanf(" %c",&ch);
        if(ch=='A'){
            scanf("%d",&num);
            heap.push(num*-1);
        }
        else if(ch=='B'){
            if(heap.empty())
                printf("-1\n");
            else{
                printf("%d\n",heap.top()*-1);
                heap.pop();
            }
        }
    }
    return 0;
}
