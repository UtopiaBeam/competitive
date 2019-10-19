#include<iostream>
int main(){
    char q=34;
    std::string a[]={
        "#include<iostream>",
        "int main(){",
        "    std::string a[]={",
        "    for(int i=0;i<4;i++)",
        "        std::cout << a[i] << std::endl;",
        "    return 0;",
        "}"};
    for(int i=0;i<3;i++)
        std::cout << a[i] << std::endl;
    for(int i=0;i<3;i++)
        std::cout << "    " << a[i] << std::endl;
    return 0;
}
