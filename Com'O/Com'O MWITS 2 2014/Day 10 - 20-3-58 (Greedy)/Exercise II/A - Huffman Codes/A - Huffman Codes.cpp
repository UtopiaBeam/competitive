#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
map <char,int> fre;
string word;
int main(){
    cin >> word;
    for(int i=0;i<word.length();i++)
        fre[word.at(i)]++;

    return 0;
}
