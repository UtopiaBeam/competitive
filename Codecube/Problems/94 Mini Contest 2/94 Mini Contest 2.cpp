#include<cstdio>
int n;
char a[100002];
int main(){
    scanf("%d %s",&n,a);
    for(int i=1;a[i];i++)
        if(a[i]==a[i-1]){
            printf("Wrong Answer\n");
            return 0;
        }
    printf("Accepted\n");
    return 0;
}
