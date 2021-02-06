#include <bits/stdc++.h>
#include "Project.h"
const int MAX=150;
using namespace std;
int main(){
    char* full;
    char* command;
    char* argument;
    do{
        full=new char[MAX];
        cout<<"$ ";
        cin.getline(full, MAX, '\n');
        cout<<full<<endl;
        full=strtok(full, " ");
        command=new char[strlen(full)+1];
        strcpy(command,full);
        cout<<command<<' '<<strlen(command)<<endl;
        full=strtok(NULL, " ");
        argument=new char[strlen(full)+1];
        strcpy(argument,full);
        cout<<argument<<' '<<strlen(argument)<<endl;
        delete[] full;
        delete[] command;
        delete[] argument;
    } while (1);
}