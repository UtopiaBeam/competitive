/*
TASK: BST Entry
LANG: C
AUTHOR: Natchapol Srisang
CENTER: Princess Chulabhron's College, Chonburi
*/
#include<stdio.h>
int cnt,tree[300010],a;
void insert(int n){
    cnt++;
    if(a<tree[n])
        if(tree[2*n+1]==0)
            tree[2*n+1]=a;
        else
            insert(2*n+1);
    else
        if(tree[2*n+2]==0)
            tree[2*n+2]=a;
        else
            insert(2*n+2);
}
int main(){
    int n,i;
    scanf("%d",&n);
    scanf("%d",&a);
    tree[0]=a;
    printf("0\n");
    for(i=1;i<n;i++){
        scanf("%d",&a);
        insert(0);
        printf("%d\n",cnt);
    }
    return 0;
}
