#include<stdio.h>
int root[100010],num[100010];
int find(int i){
    if(root[i]!=i)
        root[i]=find(root[i]);
    return root[i];
}
int main(){
    int n,m,i,a,b,roota,rootb;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
        root[i]=i;
    }
    while(m--){
        scanf("%d %d",&a,&b);
        roota=find(a);  rootb=find(b);
        if(num[roota]<num[rootb]){
            root[roota]=rootb;
            printf("%d\n",rootb);
            num[rootb]+=num[roota]/2;
        }
        else if(num[roota]>num[rootb]){
            root[rootb]=roota;
            printf("%d\n",roota);
            num[roota]+=num[rootb]/2;
        }
        else if(roota>rootb){
            root[roota]=rootb;
            printf("%d\n",rootb);
            num[rootb]+=num[roota]/2;
        }
        else if(roota<rootb){
            root[rootb]=roota;
            printf("%d\n",roota);
            num[roota]+=num[rootb]/2;
        }
        else    printf("-1\n");
    }
    return 0;
}
