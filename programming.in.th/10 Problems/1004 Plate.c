#include<stdio.h>
#include<stdlib.h>
int c,s,i;
typedef struct Student{
    int Class,ID,chk;
}STDNT;
STDNT student[1010];
typedef struct list{
    int Class;
    int ID;
    struct list *next;
}list;
int Chk=1;
list *front=NULL;
list *create(int id){
    list *node;
    node=(list *)malloc(sizeof(list));
    node->ID=id;
    for(i=0;i<s;i++)
        if(student[i].ID==id){
            node->Class=student[i].Class;
            break;
        }
    node->next=NULL;
    return node;
}
void enqueue(int id){
    list *node,*cur=front;
    node=create(id);
    while(cur->next!=NULL){
        if(cur->Class==node->Class && cur->next->Class!=node->Class){
            node->next=cur->next;
            cur->next=node;
            return ;
        }
        else    cur=cur->next;
    }
    if(cur->next==NULL)     cur->next=node;
}
void dequeue(){
    list *node=front;
    if(front==NULL){
        printf("empty\n");
        return ;
    }
    for(i=0;i<s;i++)
        if(student[i].ID==node->ID && student[i].chk!=0){
            printf("%d\n",node->ID);
            student[i].chk=0;
        }
    front=front->next;
    if(front==NULL)     Chk=1;
    free(node);
}
int main(){
    char ch;
    int id;
    scanf("%d %d",&c,&s);
    for(i=0;i<s;i++){
        scanf("%d %d",&student[i].Class,&student[i].ID);
        student[i].chk=1;
    }
    while(1){
        scanf(" %c",&ch);
        if(ch=='X')     break;
        if(ch=='E'){
            scanf("%d",&id);
            if(Chk)     front=create(id);
            else        enqueue(id);
            Chk=0;
        }
        if(ch=='D')     dequeue();
    }
    printf("0\n");
    return 0;
}
