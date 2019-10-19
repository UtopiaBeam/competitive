#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int> heap;
int main(){
    int q,i;
    char ch;
    scanf("%d",&q);
    while(q--){
        scanf(" %c",&ch);
        if(ch=='Q'){
            if(heap.empty())
                printf("-1\n");
            else{
                printf("%d\n",heap.top());
                heap.pop();
            }
        }
        else if(ch=='P'){
            scanf("%d",&i);
            heap.push(i);
        }
    }
    return 0;
}
