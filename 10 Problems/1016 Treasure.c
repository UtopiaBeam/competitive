#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
double x=0.000,y=0.000,d=0.000,lng=0.000,sin45=sqrt(2)/2.000;
char ch[2600];
int main(){
    int len,i;
    gets(ch);
    len=strlen(ch)-1;
    for(i=0;i<len;i++){
        if(isdigit(ch[i]))
            lng=lng*10.000+(double)(ch[i]-'0');
        else if(ch[i]==' ')
            lng=0.000;
        else if(ch[i]=='N'){
            if(ch[i+1]=='E')
                x+=lng*sin45,y+=lng*sin45,i++;
            else if(ch[i+1]=='W')
                x-=lng*sin45,y+=lng*sin45,i++;
            else
                y+=lng;
        }
        else if(ch[i]=='S'){
            if(ch[i+1]=='E')
                x+=lng*sin45,y-=lng*sin45,i++;
            else if(ch[i+1]=='W')
                x-=lng*sin45,y-=lng*sin45,i++;
            else
                y-=lng;
        }
        else if(ch[i]=='E')     x+=lng;
        else if(ch[i]=='W')     x-=lng;
    }
    d=sqrt(x*x+y*y);
    printf("%.3lf %.3lf\n%.3lf",x,y,d);
    return 0;
}
