#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *q,n,front=0,rear=0,size=0;
void create(int num){
    q=(int *)malloc(sizeof(int)*num);
}
void enqueue(int num){
    if(size==n)     printf("The queue is FULL.\n");
    else    q[rear++%n]=num,size++;
}
void dequeue(){
    if(size==0)     printf("The queue is EMPTY.\n");
    else    front++,size--;
}
void printQ(){
    if(size==0)     printf("The queue is EMPTY.\n");
    else{
        for(int i=front;i<rear;i++)
            printf("%d ",q[i%n]);
        printf("\n");
    }
}
void clearQ(){
    while(front<rear)   front++;
    size=0;
}
int main(){
    int cmd,num;
    printf("MENU\n1 N for create a N-size queue.\n2 N for enqueue N.\n3   for dequeue.\n4   for show the front.\n5   for show the rear.\n6   for show all element(s) in queue.\n7   for clear the queue.\n8   for exit.\n");
    while(scanf("%d",&cmd) && cmd!=8){
        if(cmd==1){
            scanf("%d",&n);
            create(n);
        }
        else if(cmd==2){
            scanf("%d",&num);
            enqueue(num);
        }
        else if(cmd==3)     dequeue();
        else if(cmd==4){
            if(size==0)     printf("The queue is EMPTY.\n");
            else    printf("%d\n",q[front%n]);
        }
        else if(cmd==5){
            if(size==0)     printf("The queue is EMPTY.\n");
            else    printf("%d\n",q[(rear-1)%n]);
        }
        else if(cmd==6)     printQ();
        else    clearQ();
    }
    return 0;
}
