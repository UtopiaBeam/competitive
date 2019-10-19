#include<cstdio>
#include<cstring>
#include<cmath>
int n;
char a[100002];
int main(){
    scanf("%d ",&n);
    while(n--){
        double x=0.0,y=0.0;
        int chk=1;
        scanf(" %s",a);
        int len=strlen(a);
        for(int i=0;i<len;i++){
            if(!strncmp(a+i,"zZZz",4))  y--,i+=3;
            else if(!strncmp(a+i,"ZzzzZ",5)){
                if(!strncmp(a+i+4,"Zzzz",4) || !strncmp(a+i+4,"ZzZzz",5) || !strncmp(a+i+4,"ZzzzZ",5))
                    y++,i+=3;
                else    x++,i+=4;
            }
            else if(!strncmp(a+i,"ZzZzz",5))  x--,i+=4;
            else if(!strncmp(a+i,"Zzzz",4))   y++,i+=3;
            else{
                printf("It isn\'t Peatty\'s snore.\n");
                chk=0;  break;
            }
//            printf("%.2lf %.2lf %d\n",x,y,i);
        }
        if(chk)     printf("%.2lf\n",sqrt(x*x+y*y));
    }
    return 0;
}
