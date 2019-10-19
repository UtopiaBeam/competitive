#include<stdio.h>
#include<stdlib.h>
int c,s,i;
typedef struct STD{
    int Class;
    int ID;
    int chk;
}Std;
Std std[1010];
typedef struct list{
    int Class;
    int ID;
    struct list *next;
}list;
int chk=1,ch=1;
list *front=NULL;
list *new(int id){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->ID=id;
    for(i=0;i<s;i++)
        if(std[i].ID==id){
            node->Class=std[i].Class;
            break;
        }
    node->next=NULL;
    return node;
}
void enqueue(int id){
    list *node,*cur=front;
    node=new(id);
    while(cur->next!=NULL){
        if(cur->Class==node->Class && cur->next->Class!=node->Class){
            node->next=cur->next;
            cur->next=node;
            break;
        }
        else    cur=cur->next;
    }
    if(cur->next==NULL)     cur->next=node;
}
void dequeue(){
    list *node=front;
    for(i=0;i<s;i++)
        if(std[i].ID==node->ID && std[i].chk!=0){
            printf("%d\n",node->ID);
            std[i],chk=0;
        }
    front=front->next;
    free(node);
    ch=0;
}
int main(){
    char ch;
    int id;
    scanf("%d %d",&c,&s);
    for(i=0;i<s;i++){
        scanf("%d %d",&std[i].Class,&std[i].ID);
        std[i].chk=1;
    }
    front=new(std[0].ID);
    while(1){
        scanf(" %c",&ch);
        if(ch=='X')     break;
        if(ch=='E'){
            scanf("%d",&id);
            if(chk)     front->ID=id;
            else        enqueue(id);
            chk=0;
        }
        if(ch=='D')     dequeue();
    }
    if(ch==1)     printf("empty\n");
    printf("0\n");
    return 0;
}
