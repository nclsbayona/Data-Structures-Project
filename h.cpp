#include <bits/stdc++.h>
const int MAX=150;
using namespace std;
int main(){
    char* input;
    while (true){
        input=new char[MAX];
        cout<<"$ ";
        cin.getline(input, MAX, '\n');
        if (!strcmp(input, "exit"))
            return 0;
    }
    return 0;
}