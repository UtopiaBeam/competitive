#include<stdio.h>
int heap[1500010],i=0;
void Upheap(int now){
    int t;
    if((now-1)/2>0){
        if(heap[now]<heap[(now-1)/2]){
            t=heap[now],heap[now]=heap[(now-1)/2],heap[(now-1)/2]=t;
            Upheap(now/2);
        }
    }
}
void Heapify(int now){
    int index,t;
    if(2*now+2<i && heap[now]<=heap[2*now+1] && heap[now]<=heap[2*now+2])
        return ;
    if(heap[2*now+1]<heap[now])
        t=heap[now],heap[now]=heap[2*now+1],heap[2*now+1]=t;
    else if(heap[2*now+2]<heap[now])
        t=heap[now],heap[now]=heap[2*now+2],heap[2*now+2]=t;
}
int main(){
    char ch;
    int n,num;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&ch);
        if(ch=='A'){
            scanf("%d",&num);
            heap[i++]=num;
            Upheap(i);
        }
        if(ch=='B'){
            if(i==0)    printf("-1\n");
            else{
                printf("%d\n",heap[0]);
                heap[0]=heap[--i];
                Heapify(i);
            }
        }
    }
    return 0;
}
