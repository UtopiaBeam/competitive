#include<cstdio>
#include<climits>
int max=INT_MIN,min=INT_MAX,n,tmp;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&tmp);
        max=(max>=tmp)*max+(max<tmp)*tmp;
        min=(min<=tmp)*min+(min>tmp)*tmp;
    }
    printf("%d\n%d\n",max,min);
    return 0;
}
