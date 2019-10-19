#include<bits/stdc++.h>
using namespace std;
char a[205],opr[]="+-*/";
stack <char> s;
int main(){
    scanf(" %s",a);
    int len=strlen(a);
    for(int i=0;i<len;i++){
        if(!isalpha(a[i]) && a[i]!='(' && a[i]!=')'){
            for(int j=0;j<4;j++){
                if(a[i]==opr[j])    break;
                if(j==3){
                    printf("ERROR\n");  return 0;
                }
            }
        }
        if(a[i]=='('){
            if(i>0 && isalpha(a[i-1])){
                printf("ERROR\n");  return 0;
           }
           s.push(a[i]);
        }
        if(a[i]==')'){
            if(s.empty()){
                printf("ERROR\n");  return 0;
            }
            s.pop();
        }
        if(i<len-1){
            if(isalpha(a[i]) && isalpha(a[i+1])){
                printf("ERROR\n");  return 0;
            }
            for(int j=0;j<4;j++)
                if(a[i]==opr[j])
                    for(int k=0;k<4;k++)
                        if(a[i+1]==opr[k]){
                            printf("ERROR\n");  return 0;
                        }
        }
    }
    if(s.empty())   printf("OK\n");
    else    printf("ERROR\n");
    return 0;
}
