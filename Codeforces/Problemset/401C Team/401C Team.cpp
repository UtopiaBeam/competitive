#include <cstdio>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
int main() {
    scanf("%d %d", &n, &m);
    int x = n-1, y = m;
    v.push_back(0);
    bool isAble = true;
    while(x > 0 || y > 0) {
        if(x-y <= 1 && y-x <= 1) {
            if(v.back() == 1 && x > 0) {
                v.push_back(0);
                x--;
            }
            else if((v[v.size()-1] == 0 || v[v.size()-2] == 0) && y > 0){
                v.push_back(1);
                y--;
            }
            else {
                isAble = false;
                break;
            }
        }
        else if(v.size() > 1 && v[v.size()-1] == 1 && v[v.size()-2] == 1) {
            if(x > 0) {
                v.push_back(0);
                x--;
            }
            else {
                isAble = false;
                break;
            }
        }
        else if(y > 0) {
            v.push_back(1);
            y--;
        }
        else {
            isAble = false;
            break;
        }
    }
    if(isAble) {
        for(int i = 0; i < v.size(); i++)
            printf("%d", v[i]);
        return 0;
    }
    v.clear();
    v.push_back(1);
    x = n, y = m-1;
    isAble = true;
    while(x > 0 || y > 0) {
        if(x-y <= 1 && y-x <= 1) {
            if(v.back() == 1 && x > 0) {
                v.push_back(0);
                x--;
            }
            else if((v[v.size()-1] == 0 || v[v.size()-2] == 0) && y > 0) {
                v.push_back(1);
                y--;
            }
            else {
                isAble = false;
                break;
            }
        }
        else if(v.size() > 1 && v[v.size()-1] == 1 && v[v.size()-2] == 1) {
            if(x > 0) {
                v.push_back(0);
                x--;
            }
            else {
                isAble = false;
                break;
            }
        }
        else if(y > 0) {
            v.push_back(1);
            y--;
        }
        else {
            isAble = false;
            break;
        }
    }
    if(isAble) {
        for(int i = 0; i < v.size(); i++)
            printf("%d", v[i]);
    }
    else        printf("-1\n");
    return 0;
}
